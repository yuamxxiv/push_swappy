/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 15:46:50 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/15 18:15:20 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*nwstr;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	nwstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!nwstr)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		nwstr[i] = f(i, s[i]);
		i++;
	}
	nwstr[i] = '\0';
	return (nwstr);
}

// char f(unsigned int position, char lettera)
// {
// 	if(position % 2 == 0 && (lettera >= 'a' && lettera <= 'z'))
// 		return (lettera - 32);
// 	return (lettera);
// }
// int	main(void)
// {
// 	char str[] = "comeNgo";
// 	char *newstr;
// 	newstr = ft_strmapi(str, f);
// 	if (newstr)
// 	{
// 	printf("str originale:%s\n", str);
// 	printf("str strmapi:%s\n", newstr);
// 	free(newstr);
// 	}
// 	return (0);
// }
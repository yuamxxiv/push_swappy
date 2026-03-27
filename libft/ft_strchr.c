/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:46:14 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:31:40 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

// int	main(void)
// {
// 	char	*s;
// 	int		c;
// 	char	*result;

// 	s = "Skit Beet";
// 	c = 't';
// 	result = ft_strchr (s, c);
// 	printf ("ft_strchr: %s\n", result);
// 	printf ("strchr: %s\n", strchr(s, c));
// 	return (0);
// }

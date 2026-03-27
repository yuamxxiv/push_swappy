/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 12:27:27 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 19:46:04 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	i;
	size_t	len;
	char	*copy;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	copy = (char *) malloc (sizeof(char) * (len +1));
	if (copy == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

/*int	main(void)
{
	char *original;
	char *copy;

	original = "Hello";
	copy = ft_strdup(original);
	printf("%s\n%p\n", original, original);
	printf("%s\n%p\n", copy, copy);
	free (copy);
	return (0);
}*/

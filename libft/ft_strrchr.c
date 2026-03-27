/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:01:20 by amancheg          #+#    #+#             */
/*   Updated: 2026/01/08 22:24:06 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}

int	main(void)
{
	char	*s;
	int		c;

	s = "Skit Bee";
	c = 't';
	printf ("ft_strrchr: %s\n", ft_strrchr(s, c));
	printf ("strrchr: %s\n", strrchr(s, c));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:30:30 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 19:47:46 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	d;

	if (!s)
		return (NULL);
	t = (unsigned char *)s;
	d = (unsigned char)c;
	while (n > 0)
	{
		if (*t == d)
			return (t);
		t++;
		n--;
	}
	return (NULL);
}

/*int main()
{
	unsigned char	s[] = "Room";
	int		c = 'o';
	size_t	n = 1;

	printf("ft_memchr:%s\n", (char *)ft_memchr(s, c, n));
	printf("memchr:%s\n", (char *)memchr(s, c, n));
}*/

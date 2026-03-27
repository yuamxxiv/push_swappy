/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 16:59:23 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 19:48:41 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	f;

	if (!s)
		return (NULL);
	d = s;
	f = c;
	while (n > 0)
	{
		*d = f;
		d++;
		n--;
	}
	return (s);
}

/*int	main(void)
{
	unsigned char	str[] = "alejandra";
	unsigned char	str2[] = "alejandra";
	unsigned char	c;
	unsigned char	d;

	c = '@';
	d = '3';
	ft_memset(str, c, 1);
	ft_memset(str +4, c, 1);
	ft_memset(str +8, c, 1);
	ft_memset(str +2, d, 1);
	printf("%s\n", str);
	memset(str2, c, 1);
	memset(str2 +4, c, 1);
	memset(str2 +8, c, 1);
	memset(str2 +2, d, 1);
	printf("%s\n", str2);
}*/

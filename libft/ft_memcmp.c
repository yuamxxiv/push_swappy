/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:18:38 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/19 23:50:20 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*m1;
	unsigned char	*m2;

	m1 = (unsigned char *) s1;
	m2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (n > 0)
	{
		if (*m1 != *m2)
			return (*m1 - *m2);
		m1++;
		m2++;
		n--;
	}
	return (0);
}

/*int	main()
{
	unsigned char s1[] = "Dopameangirls";
	unsigned char s2[] = "D0pamina";
	size_t n = 9;
	printf("ft_memcmp:%d\n", ft_memcmp(s1, s2, n));
	printf("memcmp:%d\n", memcmp(s1, s2, n));
	return(0);
}*/

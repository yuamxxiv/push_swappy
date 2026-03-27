/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:27:06 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:43:03 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	unsigned char	a;

	a = c;
	if (a >= 'A' && a <= 'Z')
		return (a + 32);
	return (c);
}

/*int	main(void)
{
	unsigned char	a;

	a = 'X';
	printf("ft_tolower:%c\n", ft_tolower(a));
	printf("tolower:%c\n", tolower(a));
	return (0);
}*/

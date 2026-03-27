/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:26:50 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:43:06 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	a;

	a = c;
	if (a >= 97 && a <= 122)
		return (a - 32);
	return (c);
}

/*int	main(void)
{
	unsigned char	a;

	a = 'w';
	printf("ft_toupper:%c\n", ft_toupper(a));
	printf("toupper:%c\n", toupper(a));
	return (0);
}*/

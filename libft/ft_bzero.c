/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:15:38 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 19:56:24 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *ptr, size_t num)
{
	unsigned char	*b;

	if (!ptr)
		return ;
	b = ptr;
	while (num > 0)
	{
		*b = 0;
		b++;
		num--;
	}
}

/*int	main(void)
{
	char	str[] = "London2Paris";

	printf ("str originale:%s\n", str);
	ft_bzero (str, 3);
	printf ("ft_bzero:%s\n", str);
	bzero (str, 3);
	printf ("bzero:%s\n", str);
}*/

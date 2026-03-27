/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:30:20 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:18 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	return (0);
}

/*int main(void)
{
	int c;
	
	c = 127;
	printf("ft_isprint:%d\n", ft_isprint(c));
	printf("isprint:%d\n", isprint(c));
}*/

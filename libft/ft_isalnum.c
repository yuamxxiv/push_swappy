/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:44:34 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:02 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int a)
{
	if ((a >= 'A' && a <= 'Z')
		|| (a >= 'a' && a <= 'z')
		|| (a >= '0' && a <= '9'))
		return (1);
	return (0);
}

/*int main(void)
{
	int c;
	c = '#';
	printf("ft_isalnum:%d\n",ft_isalnum(c));
	printnf("isalnum:%d\n",isalnum(c));
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 14:38:46 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:14 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int n)
{
	if (!(n >= '0' && n <= '9'))
		return (0);
	return (1);
}

/*int main(void)
{
	int c;
	c = 'a';
	printf("ft_isdigit:%d\n",ft_isdigit(c));
	printf("isdigit:%d\n", isdigit(c));
}
*/

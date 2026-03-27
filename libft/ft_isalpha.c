/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:59:43 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:41:06 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c < 'A' || c > 'Z') && (c < 'a' || c > 'z'))
		return (0);
	return (1);
}

/*int main(void)
{
	int c;
	c = '#';
	printf("ft_isalpha:%d\n",(ft_isalpha(c)));
	printf("isalpha:%d\n",(isalpha(c)));
}*/

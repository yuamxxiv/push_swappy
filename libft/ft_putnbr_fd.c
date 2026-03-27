/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 19:07:42 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/18 15:42:51 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}
// int	main(void)
// {
// 	ft_putstr_fd("Test 42: ", 1);
//     ft_putnbr_fd(42, 1);
//     ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Test -42: ", 1);
//     ft_putnbr_fd(-42, 1);
//     ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Test 0: ", 1);
//     ft_putnbr_fd(0, 1);
//     ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Test INT_MIN: ", 1);
//     ft_putnbr_fd(-2147483648, 1);
//     ft_putchar_fd('\n', 1);
// 	ft_putstr_fd("Test INT_MAX: ", 1);
//     ft_putnbr_fd(2147483647, 1);
//     ft_putchar_fd('\n', 1);
// 	return (0);
// }

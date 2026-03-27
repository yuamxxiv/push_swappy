/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:58:45 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/17 22:15:32 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// int main(void)
// {
//     int fd = open("aaaa", O_WRONGLY | O_CREATE, 0644);
//     int fd1 = open("aaaa",_WRONGLY | O_CREATE, 0644);
//     ft_putchar_fd('a', fd);
//     ft_putchar_fd('a', fd1);
//     printf("%d\n", fd);
//     printf("%d\n", fd1);
// }
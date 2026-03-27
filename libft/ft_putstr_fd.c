/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 13:28:05 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/18 16:01:52 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0')
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	return ;
}
// int main(void)
// {
// 	ft_putstr_fd("1. Ciao! Questo messaggio va sul terminale.\n", 1);
// 	ft_putstr_fd("2. Questo è un messaggio di errore (fd 2).\n", 2);
// 	int mio_fd = open("prova.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	if (mio_fd == -1)
//  {
//		printf("Errore nell'apertura del file!\n");
//      return (1);
//   }
// 	ft_putstr_fd("3.the function wrote on the file\n", mio_fd);
//     close(mio_fd);
//     printf("\nTest 3 completato. file 'prova.txt' nella cartella!\n");
//     return (0);
// }
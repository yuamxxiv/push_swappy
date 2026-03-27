/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:29:27 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 19:52:44 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static void	ft_putint( char *str, long nb, int len)
{
	str[len] = '\0';
	len--;
	if (nb == 0)
	{
		str[0] = '0';
		return ;
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	while (nb > 0)
	{
		str[len] = (nb % 10) + '0';
		nb = nb / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	char	*str;

	nb = n;
	len = ft_intlen(nb);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ft_putint(str, nb, len);
	return (str);
}

/*int main(void)
{
	int nb;
	char *str;

	nb = -2214143;
	str = ft_itoa(nb);
	if (str) // controllo per malloc se ha fallito
	{
	printf("numero int:%d\n", nb);
	printf("numero ascii:%s\n", str);
	free (str);
	}
	return (0);    
}*/
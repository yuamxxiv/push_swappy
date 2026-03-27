/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 18:17:48 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/15 19:40:10 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
// void    f(unsigned int position, char *lettera_ptr)
// {
// 	if(position % 2 == 0 && (*lettera_ptr >= 'a' && *lettera_ptr <= 'z'))
//        *lettera_ptr = *lettera_ptr -32; 
// }
// int main(void)
// {
// 	char str[] = "comeNgo";
// 	ft_striteri(str, f);
// 	printf("str strteri:%s\n", str);
// 	return (0);
// }
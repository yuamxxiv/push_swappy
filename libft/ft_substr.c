/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:11:36 by amancheg          #+#    #+#             */
/*   Updated: 2026/01/08 22:30:23 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	len_effettiva;	
	char	*ptr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	len_effettiva = s_len - start;
	if (len_effettiva > len)
		len_effettiva = len;
	ptr = (char *) malloc (sizeof(char) * (len_effettiva + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len_effettiva)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

int main(void)
{
	char *str_o = "HeHeHello";
	char *str_s;
	int start;
	size_t len;
	
	start = 4;
	len = 4;
	str_s = ft_substr(str_o, start, len);
	printf("%s\n", str_s);
	free (str_s);
	return (0);
}

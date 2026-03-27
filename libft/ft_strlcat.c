/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 23:29:43 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/22 20:00:02 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;
	size_t	dst_len;

	if (!dst || !src)
		return (0);
	dst_len = 0;
	while (dst[dst_len] != '\0' && dst_len < size)
		dst_len++;
	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	if (dst_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && (dst_len + i) < size -1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*int main(void)
{
	char dst1[42] = "Secret ";
	char dst2[42] = "Secret ";
	char src[] = "Piano ";
	size_t buffer = 42;
	
	size_t result_ft = ft_strlcat(dst1, src, buffer);
	size_t result_std = strlcat(dst2, src, buffer);
	
	printf("ft_strlcat: %zu -> dst: '%s'\n", result_ft, dst1);
	printf("strlcat:    %zu -> dst: '%s'\n", result_std, dst2);
	
	return (0);
}*/
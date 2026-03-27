/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:12:16 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/12 19:42:26 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
		src_len++;
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < size -1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (src_len);
}

/*int	main(void)
{
	char src[] = "Karma Loop";
	char dst[20];
	size_t buffer = 13;
	printf("ft_strlcpy:%zu\n", ft_strlcpy(dst, src, buffer));
	printf("Risultato in dst: %s\n", dst);
	printf("strlcpy:%zu\n", strlcpy(dst, src, buffer));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:15:24 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/18 13:44:38 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ns = (char *)malloc (((ft_strlen(s1) + ft_strlen(s2)) + 1) * sizeof(char));
	if (!ns)
		return (NULL);
	i = 0;
	j = 0;
	while (i < ft_strlen(s1))
	{
		ns[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		ns[i + j] = s2[j];
		j++;
	}
	ns[i + j] = '\0';
	return (ns);
}

// int main(void)
// {
// 	char s1[] = "Baby ";
// 	char s2[] = "Hello";
// 	char *ns;

// 	ns = ft_strjoin(s1, s2);
// 	if (ns)
// 	{
// 	   printf ("%s\n", ns);
// 	   free (ns);
// 	}
// 	return (0);
// }
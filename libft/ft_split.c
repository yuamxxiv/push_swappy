/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:28:03 by amancheg          #+#    #+#             */
/*   Updated: 2026/01/08 17:47:16 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	conta_parole(char const *s, char c)
{
	int	i;
	int	cp;

	i = 0;
	cp = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			cp++;
		i++;
	}
	return (cp);
}

static char	**free_tutto(char **arrns, int ac)
{
	int	ipc;

	ipc = 0;
	while (ipc < ac)
	{
		free (arrns[ipc]);
		ipc++;
	}
	free (arrns);
	return (NULL);
}

static char	*alloca_parola(char const *s, char c, int j)
{
	int		len_pa;
	int		temp;
	int		k;
	char	*parola;

	len_pa = 0;
	temp = j;
	while (s[temp] != c && s[temp] != '\0')
	{
		len_pa++;
		temp++;
	}
	parola = malloc(sizeof(char) * (len_pa + 1));
	if (!parola)
		return (NULL);
	k = 0;
	while (k < len_pa)
	{
		parola[k] = s[j + k];
		k++;
	}
	parola[k] = '\0';
	return (parola);
}

static char	**nuovo_array(int cp)
{
	char	**arrns;

	arrns = malloc(sizeof(char *) * (cp + 1));
	if (!arrns)
		return (NULL);
	arrns[cp] = NULL;
	return (arrns);
}

char	**ft_split(char const *s, char c)
{
	char	**arrns;
	int		j;
	int		ac;

	if (!s)
		return (NULL);
	arrns = nuovo_array(conta_parole(s, c));
	if (!arrns)
		return (NULL);
	j = 0;
	ac = 0;
	while (s[j] != '\0')
	{
		if (s[j] != c && (j == 0 || s[j - 1] == c))
		{
			arrns[ac] = alloca_parola(s, c, j);
			if (!arrns[ac])
				return (free_tutto (arrns, ac));
			ac++;
		}
		j++;
	}
	return (arrns);
}

// int main(void)
// {
// 	char	s[] = "Analog**Odyssey**Lofi**Cassette";
// 	char	c = '*';
// 	char	**arr;
// 	int 	i;

// 	arr = ft_split(s, c);
// 	printf("stringa:%s\n", arr[0]);
// 	printf("stringa:%s\n", arr[1]);
// 	printf("stringa:%s\n", arr[2]);
// 	printf("stringa:%s\n", arr[3]);
// 	i = 0;
// 	while (arr[i] != NULL)
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return(0);
// }
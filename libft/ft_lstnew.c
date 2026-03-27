/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 21:32:48 by amancheg          #+#    #+#             */
/*   Updated: 2025/12/18 14:47:57 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_nodo;

	new_nodo = (t_list *)malloc(sizeof(t_list));
	if (!new_nodo)
		return (NULL);
	new_nodo -> content = content;
	new_nodo -> next = NULL;
	return (new_nodo);
}
// int main(void)
// {
// 	char *str = "Ciao, sono un nodo";
// 	t_list *new_nodo = ft_lstnew(str);
// 	if (new_nodo == NULL)
// 	{
// 		printf("malloc fallita\n");
// 		return (1);
// 	}
// 	printf("contenuto atteso:%s\n", str);
// 	printf("contenuto reale:%s\n", (char *) new_nodo -> content);
// 	if (new_nodo -> next == NULL)
// 		printf("next pointer: NULL\n");
// 	else
// 		printf("next pointer(errore): %p\n", new_nodo -> next);
// 	return (0);
// }
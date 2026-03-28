/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:41:37 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/28 23:42:42 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void push (t_stack_node **dest, t_stack_node **src)
// {
//     t_stack_node    *push_node;
//     if (!*src)
//         return ;
//     push_node = *src;
//     *src = (*src) -> next;
//     if (*src)
//         (*src) -> prev = NULL;
//     push_node -> prev = NULL;
//     if (!*dest)
//     {
//         *dest = push_node;
//         push_node -> next = NULL;
//     }
//     else 
//     {
//         push_node -> next = *dest;
//         (*dest) -> prev = push_node;
//         *dest = push_node;
//     }
// }

static void	push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	t_stack_node	*new_src_top;

	if (!src || !*src)
		return ;
	node_to_push = *src;
	new_src_top = (*src)->next;
	*src = new_src_top;
	if (new_src_top)
		new_src_top->prev = NULL;
	node_to_push->next = NULL;
	node_to_push->prev = NULL;
	if (!*dest)
	{
		*dest = node_to_push;
		return ;
	}
	node_to_push->next = *dest;
	(*dest)->prev = node_to_push;
	*dest = node_to_push;
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	write (1, "pa\n", 3);
}

void	pb(t_stack_node **b, t_stack_node **a)
{
	push(b, a);
	write (1, "pb\n", 3);
}

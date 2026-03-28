/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:43:39 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 17:18:38 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void reverse_rotate(t_stack_node **stack)
// {
//     t_stack_node *last;
//     if (!stack || !*stack || (!(*stack) -> next))
//         return ;
//     last = stack_last (*stack);
//     last-> prev-> next = NULL;
//     last-> next = *stack;
//     last-> prev = NULL;
//     (*stack) -> prev = last;
//     *stack = last;
// }
static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;
	t_stack_node	*second_to_last;
	t_stack_node	*first_node;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = stack_last(*stack);
	second_to_last = last_node->prev;
	second_to_last->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = last_node;
}

void	rra(t_stack_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}

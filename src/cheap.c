/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:57:01 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/01 18:57:23 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//cercare il nodo che ha il costo da spostare piu basso di tutti
void	find_cheapest(t_stack_node *stack)
{
	t_stack_node	*cheapest_node;
	long				lowest_cost;

	if (!stack)
		return ;
	cheapest_node = NULL;
	lowest_cost = LONG_MAX;
	while (stack)
	{
		stack->cheapest = false;
		if (stack->push_cost < lowest_cost)
		{
			lowest_cost = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	if (cheapest_node)
		cheapest_node->cheapest = true;
}

void	move_cheapest(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
	{
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rr(a, b);
	}
	else if (!cheapest_node->above_median
		&& !cheapest_node->target_node->above_median)
	{
		while (*a != cheapest_node && *b != cheapest_node->target_node)
			rrr(a, b);
	}
	finish_rotation(a, cheapest_node, 'a');
	finish_rotation(b, cheapest_node, 'b');
	pb(b, a);
}

//funzione helper di move cheapest 
//fa girare lo stack finche il nodo desiderato non arriva in cima
void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char name)
{
	while (*stack != top_node)
	{
		if (name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

//funzione helper di move cheapest 
//scorre a e ritorna il nodo con cheapest == true
t_stack_node	*get_cheapest(t_stack_node *stack)
{
	t_stack_node	*current_node;

	current_node = stack;
	while (current_node)
	{
		if (current_node->cheapest)
			return (current_node);
		current_node = current_node->next;
	}
	return (NULL);
}

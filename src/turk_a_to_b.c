/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 19:31:40 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/02 19:45:17 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack_node *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_size(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_target_a(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*target_node;
	long			best_match;

	while (a)
	{
		best_match = LONG_MIN;
		target_node = NULL;
		current_b = b;
		while (current_b)
		{
			if (current_b->nbr < a->nbr && current_b->nbr > best_match)
			{
				best_match = current_b->nbr;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (!target_node)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}

static int	get_node_cost(t_stack_node *node, int stack_len)
{
	if (node->above_median)
		return (node->index);
	return (stack_len - node->index);
}

void	calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		cost_a = get_node_cost(a, len_a);
		cost_b = get_node_cost(a->target_node, len_b);
		if (a->above_median == a->target_node->above_median)
		{
			a->push_cost = cost_b;
			if (cost_a > cost_b)
				a->push_cost = cost_a;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

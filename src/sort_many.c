/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:46:49 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/28 23:31:53 by amancheg         ###   ########.fr       */
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
		if (a->above_median)
			cost_a = a->index;
		else
			cost_a = len_a - a->index;
		if (a->target_node->above_median)
			cost_b = a->target_node->index;
		else
			cost_b = len_b - a->target_node->index;
		if (a->above_median == a->target_node->above_median)
		{
			if (cost_a > cost_b)
				a->push_cost = cost_a;
			else
				a->push_cost = cost_b;
		}
		else
			a->push_cost = cost_a + cost_b;
		a = a->next;
	}
}

//ora b e quasi finito quindi dobbiamo reinserire ogni nodo di b nel posto giusto in a 
void	find_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_a;
	t_stack_node	*target;

	while (b)
	{
		target = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr)
			{
				if (!target || current_a->nbr < target->nbr)
					target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
			b->target_node = find_min(a);
		else
			b->target_node = target;
		b = b->next;
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
		if(!target_node)
			a->target_node = find_max(b);
		else
			a->target_node = target_node;
		a = a->next;
	}
}
t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max_node;

	if (!stack)
		return (NULL);
	max_node = stack;
	while (stack)
	{
		if (stack-> nbr > max_node->nbr)
			max_node = stack;
		stack = stack->next; 
	}
	return (max_node);
}

//funzione helper per find target 
t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min_node;

	if (!stack)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->nbr < min_node->nbr)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

//funzione helper per find target  che trova il nodo con il valore minimo in a
t_stack_node	*get_min(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*min_node;

	current_node = stack;
	min_node = stack;
	while (current_node)
	{
		if (current_node->nbr < min_node->nbr)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

void	move_back(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*target;

	target = (*b)->target_node;
	while (*a != target)
	{
		if (target->above_median)
			ra(a);
		else
			rra(a);
	}
	pa(a, b);
}

void	bring_min_top(t_stack_node **a)
{
	t_stack_node	*min;

	set_index(*a);
	min = get_min(*a);
	while (*a != min)
	{
		if (min->above_median)
			ra(a);
		else
			rra(a);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuam <yuam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/26 20:46:49 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 12:46:11 by yuam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(t_stack_node *stack)
{
	int i;
	int median;

	i = 0;
	if(!stack)
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
void calculate_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int cost_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	while (a)
	{
		cost_a = a->index;
		if (!(a->above_median))
			cost_a = len_a - a->index;
		cost_b = a->target_node -> index;
		if (!(a->target_node->above_median))
			cost_b = len_b - a->target_node->index;
		if (a->above_median && a->target_node->above_median)
			a->push_cost = (cost_a > cost_b) ? cost_a : cost_b;
		else if (!(a->above_median) && !(a->target_node->above_median))
            a->push_cost = (cost_a > cost_b) ? cost_a : cost_b;
        else
            a->push_cost = cost_a + cost_b;

        a = a->next;
	}
}

//ora b e quasi finito quindi dobbiamo reinserire ogni nodo di b nel posto giusto in a 
void find_target(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current_b;
	t_stack_node	*current_a;
	t_stack_node	*target;
	long			best_match;

	current_b = b;
	while (current_b)
	{
		best_match = LONG_MAX;
		target = NULL;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > current_b->nbr
				&& current_a->nbr < best_match)
			{
				best_match = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (!target)
			target = get_min(a);
		current_b->target_node = target;
		current_b = current_b->next;
	}
}

//funzione helper per find target  che trova il nodo con il valore minimo in a
t_stack_node *get_min(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*min_node;

	current_node = stack;
	min_node = stack;
	while(current_node)
	{
		if (current_node->nbr < min_node->nbr)
			min_node = current_node;
		current_node = current_node->next;
	}
	return (min_node);
}

void move_back(t_stack_node **a, t_stack_node **b)
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

void bring_min_top(t_stack_node **a)
{
	t_stack_node *min;
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

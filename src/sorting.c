/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 19:49:50 by amancheg          #+#    #+#             */
/*   Updated: 2026/04/04 00:12:58 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	if (!stack || !stack->next)
		return (1);
	current_node = stack;
	while (current_node-> next)
	{
		next_node = current_node-> next;
		if (current_node->nbr > next_node->nbr)
			return (0);
		current_node = current_node -> next;
	}
	return (1);
}

void	sort_three(t_stack_node **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->nbr;
	second = (*stack)->next->nbr;
	third = (*stack)->next->next->nbr;
	if (first > second && first > third)
	{
		ra(stack);
		first = (*stack)->nbr;
		second = (*stack)->next->nbr;
	}
	else if (second > first && second > third)
	{
		rra(stack);
		first = (*stack)->nbr;
		second = (*stack)->next->nbr;
	}
	if (first > second)
		sa(stack);
}

// void	sort_three(t_stack_node **stack)
// {
// 	int	first;
// 	int	second;
// 	int	third;

// 	first = (*stack)->nbr;
// 	second = (*stack)->next->nbr;
// 	third = (*stack)->next->next->nbr;
// 	if (first > second && second < third && first < third)
// 		sa(stack);
// 	else if (first < second && second > third && first > third)
// 		rra(stack);
// 	else if (first > second && second > third && first > third)
// 	{
// 		sa(stack);
// 		rra(stack);
// 	}
// 	else if (first < second && second > third && first < third)
// 	{
// 		sa(stack);
// 		ra(stack);
// 	}
// 	else if (first > second && second < third && first > third)
// 		ra(stack);
// }

// void	sort_many(t_stack_node **a, t_stack_node **b)
// {
// 	pb(b, a);
// 	pb(b, a);
// 	while (stack_size(*a) > 3)
// 	{
// 		set_index(*a);
// 		set_index(*b);
// 		init_target_a(*a, *b);
// 		calculate_cost(*a, *b);
// 		find_cheapest(*a);
// 		move_cheapest(a, b);
// 	}
// 	sort_three(a);
// 	while (*b)
// 	{
// 		find_target(*a, *b);
// 		move_back(a, b);
// 	}
// 	bring_min_top(a);
// }
static void	move_a_to_b(t_stack_node **a, t_stack_node **b)
{
	set_index(*a);
	set_index(*b);
	init_target_a(*a, *b);
	calculate_cost(*a, *b);
	find_cheapest(*a);
	move_cheapest(a, b);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	set_index(*a);
	set_index(*b);
	find_target_b(*a, *b);
	move_back(a, b);
}

void	sort_many(t_stack_node **a, t_stack_node **b)
{
	int	len_a;

	len_a = stack_size(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	if (len_a-- > 3 && !is_sorted(*a))
		pb(b, a);
	while (len_a-- > 3 && !is_sorted(*a))
		move_a_to_b(a, b);
	sort_three(a);
	while (*b)
		move_b_to_a(a, b);
	set_index(*a);
	bring_min_top(a);
}

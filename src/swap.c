/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuam <yuam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 20:05:29 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 13:09:05 by yuam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void swap (t_stack_node **stack)
// {
// 	int tmp_nbr;
// 	if (!stack || !*stack || !((*stack)-> next))
// 		return ;
	
// 	tmp_nbr = (*stack)-> nbr;
// 	(*stack)->nbr = (*stack)->next->nbr;
// 	(*stack)->next->nbr = tmp_nbr;
// }

static void swap (t_stack_node **stack)
{
	t_stack_node    *first_node;
	t_stack_node    *second_node;
	int				tmp_nbr;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = first_node->next;
	tmp_nbr = first_node -> nbr;
	first_node->nbr = second_node->nbr;
	second_node->nbr = tmp_nbr;
}


void   sa(t_stack_node **a)
{
	swap (a);
	write (1, "sa\n", 3);
}

void    sb(t_stack_node **b)
{
	swap (b);
	write (1, "sb\n", 3);
}





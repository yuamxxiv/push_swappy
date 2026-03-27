/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuam <yuam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 19:42:33 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 13:08:45 by yuam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void rotate (t_stack_node **stack)
// {
//     t_stack_node *last;
//     t_stack_node *first;

//     if (!stack || !*stack || !((*stack) -> next))
//         return ;
//     first = *stack;
//     last = stack_last (*stack);
//     *stack = first -> next;
//     (*stack) -> prev = NULL;
//     last -> next = first;
//     first -> prev = last;
//     first -> next = NULL;
// }

static void rotate (t_stack_node **stack)
{
    t_stack_node *first_node;
    t_stack_node *second_node;
    t_stack_node *last_node;
    if (!stack || !*stack || !((*stack)-> next))
        return ;
    first_node = *stack;
    second_node = first_node-> next;
    last_node = stack_last(*stack);
    second_node-> prev = NULL;
    *stack = second_node;

    last_node-> next = first_node;
    first_node-> prev = last_node;
    first_node-> next = NULL;
    
}

void ra (t_stack_node **a)
{
    rotate (a);
    write (1, "ra\n", 3);
}

void rb (t_stack_node **b)
{
    rotate (b);
    write (1, "rb\n", 3);
}

void rr (t_stack_node **a,t_stack_node **b)
{
    rotate (a);
    rotate (b);
    write (1, "rr\n", 3);
}
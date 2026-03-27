/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuam <yuam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 21:10:40 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 13:07:02 by yuam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//questa versione di atoi controlla che il numero che si sta inserendo non 
//supera INT_MAX o INT_MIN

long long	ft_atol(const char *nptr, bool *error)
{
	int			sign;
	long long	n;

	if (!nptr)
		return (0);
	sign = 1;
	n = 0;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		n = n * 10 + (*nptr++ - '0');
		if ((n * sign) > INT_MAX || (n * sign) < INT_MIN)
			return (*error = true, 0);
	}
	if (*nptr != '\0')
		*error = true;
	return (n * sign);
}
//controlla se una stringa contiene solo numeri || segni + -

int	is_number(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}
//scorre lo stack per vedere se il numero che si sta inserendo esiste gia'

int	is_duplicate(t_stack_node *stack_a, int n)
{
	if (!stack_a)
		return (0);
	while (stack_a)
	{
		if (stack_a -> nbr == n)
			return (1);
		stack_a = stack_a -> next;
	}
	return (0);
}
//funzione che prende argv e fa il check con le funzioni sopra e riempe 
//lo stack_a

void	parse_input(t_stack_node **stack_a, char **argv, int argc)
{
	char		**args;
	int			i;
	long long	n;
	bool		error_atoi;
	bool		is_single_arg;

	is_single_arg = (argc == 2);
	if(is_single_arg)
		args = ft_split(argv[1], ' ');
	else
		args = argv;
	if (is_single_arg)
		i = 0;
	else 
		i = 1;
	while (args[i])
	{
		error_atoi = false;
		if (!is_number(args[i]))
			free_error(stack_a, args, is_single_arg);
		n = ft_atol(args[i], &error_atoi);
		if(error_atoi || is_duplicate(*stack_a, (int)n))
			free_error (stack_a, args, is_single_arg);
		stack_add_back(stack_a, stack_new((int *)n));
		i++;
	}
	if (is_single_arg)
		free_split (args);
	return ;
}

void	free_error(t_stack_node **stack, char **args, bool ft_split)
{
	free_stack(stack);
	if (ft_split && args)
		free_split(args);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*tmp;
	t_stack_node	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current)
	{
		tmp = current -> next;
		free (current);
		current = tmp;
	}
	*stack = NULL;
}

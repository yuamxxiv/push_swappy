/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amancheg <amancheg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/27 17:10:05 by amancheg          #+#    #+#             */
/*   Updated: 2026/03/27 20:10:09 by amancheg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	parse_input(t_stack_node **stack_a, char **argv, int argc)
{
	char		**args;
	int			i;
	long long	n;
	bool		error_atoi;
	bool		is_single_arg;

	is_single_arg = (argc == 2);
	if (is_single_arg)
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
		if (error_atoi || is_duplicate(*stack_a, (int)n))
			free_error (stack_a, args, is_single_arg);
		stack_add_back(stack_a, stack_new((n)));
		i++;
	}
	if (is_single_arg)
		free_split (args);
	return ;
}
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

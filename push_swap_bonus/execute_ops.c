/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:15:15 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:16:53 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_swap(char *ops, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(ops, "sa", 2) && ops[2] == '\n')
		return (swap(*stack_a), 1);
	else if (!ft_strncmp(ops, "sb", 2) && ops[2] == '\n')
		return (swap(*stack_b), 1);
	else if (!ft_strncmp(ops, "ss", 2) && ops[2] == '\n')
	{
		swap(*stack_a);
		swap(*stack_b);
		return (1);
	}
	return (0);
}

int	check_push(char *ops, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(ops, "pa", 2) && ops[2] == '\n')
		return (push(stack_b, stack_a), 1);
	else if (!ft_strncmp(ops, "pb", 2) && ops[2] == '\n')
		return (push(stack_a, stack_b), 1);
	return (0);
}

int	check_rotate(char *ops, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(ops, "ra", 2) && ops[2] == '\n')
		return (rotate(stack_a), 1);
	else if (!ft_strncmp(ops, "rb", 2) && ops[2] == '\n')
		return (rotate(stack_b), 1);
	else if (!ft_strncmp(ops, "rr", 2) && ops[2] == '\n')
		return (rotate(stack_a), rotate(stack_b), 1);
	return (0);
}

int	check_r_rotate(char *ops, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(ops, "rra", 3) && ops[3] == '\n')
		return (r_rotate(stack_a), 1);
	else if (!ft_strncmp(ops, "rrb", 3) && ops[3] == '\n')
		return (r_rotate(stack_b), 1);
	else if (!ft_strncmp(ops, "rrr", 3) && ops[3] == '\n')
		return (r_rotate(stack_a), r_rotate(stack_b), 1);
	return (0);
}

void	execute_ops(char *ops, t_list **stk_a, t_list **stk_b, t_collect *var)
{
	if (check_swap(ops, stk_a, stk_b))
		return ;
	else if (check_push(ops, stk_a, stk_b))
		return ;
	else if (check_rotate(ops, stk_a, stk_b))
		return ;
	else if (check_r_rotate(ops, stk_a, stk_b))
		return ;
	else
		free_and_exit(var);
}

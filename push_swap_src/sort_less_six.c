/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_six.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:55:58 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 11:57:06 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_list *stack_a)
{
	int	max;

	max = *(int *)stack_a->content;
	while (stack_a)
	{
		if (*(int *)stack_a->content > max)
			max = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (max);
}

void	sort_stack_three(t_list **stack_a, int len)
{
	int	max;

	if (ab_is_sorted(*stack_a, len, ORDER_STACK_A))
		return ;
	max = get_max(*stack_a);
	if ((*(int *)(*stack_a)->content) == max)
		rotate_a(stack_a);
	else if ((*(int *)(*stack_a)->next->content) == max)
		r_rotate_a(stack_a);
	if ((*(int *)(*stack_a)->content) > (*(int *)(*stack_a)->next->content))
		swap_a(*stack_a);
}

void	sort_stack_five(t_stacks *ls, int len, t_collect *var)
{
	int	mid;
	int	max;

	if (ab_is_sorted(*ls->stack_a, len, ORDER_STACK_A))
		return ;
	mid = get_mid(*ls->stack_a, len, var);
	max = get_max(*ls->stack_a);
	while (len > 3)
	{
		if (*(int *)(*ls->stack_a)->content < mid && len--)
			push_b(ls->stack_a, ls->stack_b);
		else
			rotate_a(ls->stack_a);
	}
	sort_stack_three(ls->stack_a, len);
	while (*ls->stack_b)
		align_and_push_a(ls->stack_a, ls->stack_b, len);
	while (*(int *)ft_lstlast(*ls->stack_a)->content != max)
		r_rotate_a(ls->stack_a);
}

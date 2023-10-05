/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_algo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:42:36 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 11:54:13 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_stack_a(t_stacks *ls, int max, int len, t_collect *var)
{
	int	mid;
	int	len_div;
	int	r_rotate;

	len_div = len;
	r_rotate = 0;
	if (len <= 1 || ab_is_sorted(*ls->stack_a, len, ORDER_STACK_A))
		return ;
	mid = get_mid(*ls->stack_a, len, var);
	while (len > (len_div / 2 + len_div % 2))
	{
		if (*(int *)(*ls->stack_a)->content < mid && len--)
			push_b(ls->stack_a, ls->stack_b);
		else if (++r_rotate && *ls->stack_b
			&& ft_lstsize(*ls->stack_b) < len_div / 2
			&& *(int *)(*ls->stack_b)->content < (mid / 2))
			rotate_ab(ls->stack_a, ls->stack_b);
		else
			rotate_a(ls->stack_a);
	}
	while (ft_lstsize(*ls->stack_a) > (len_div / 2 + len_div % 2)
		&& r_rotate-- > 0)
		r_rotate_a(ls->stack_a);
	sort_stack_a(ls, max, (len_div / 2 + len_div % 2), var);
	sort_stack_b(ls, max, len_div / 2, var);
}

void	sort_stack_b(t_stacks *ls, int max, int len, t_collect *var)
{
	int	mid;
	int	len_div;
	int	r_rotate;

	len_div = len;
	r_rotate = 0;
	if (ab_is_sorted(*ls->stack_b, len, ORDER_STACK_B))
		while (len--)
			push_a(ls->stack_b, ls->stack_a);
	if (len < 1)
		return ;
	mid = get_mid(*ls->stack_b, len, var);
	while (len > len_div / 2)
	{
		if (*(int *)(*ls->stack_b)->content >= mid && len--)
			align_and_push_a(ls->stack_a, ls->stack_b, len);
		else if (++r_rotate)
			rotate_b(ls->stack_b);
	}
	check_r_rotate_ab(ls->stack_a, ls->stack_b, len_div / 2, r_rotate);
	sort_stack_a(ls, max, (len_div / 2 + len_div % 2), var);
	sort_stack_b(ls, max, len_div / 2, var);
}

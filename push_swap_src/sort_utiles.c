/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:58:27 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:06:46 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ab_is_sorted(t_list *ls, int len, int order)
{
	while (ls->next && --len > 0)
	{
		if ((*(int *)ls->content > *(int *)ls->next->content
				&& order == ORDER_STACK_A)
			|| (*(int *)ls->content < *(int *)ls->next->content
				&& order == ORDER_STACK_B))
			return (0);
		ls = ls->next;
	}
	return (1);
}

int	get_mid(t_list *nbrs, int len, t_collect *var)
{
	int	mid;
	int	*stack;
	int	i;

	i = 0;
	stack = (int *)malloc(len * sizeof(int));
	if (!stack)
		free_and_exit(var);
	while (i < len)
	{
		stack[i] = *(int *)nbrs->content;
		nbrs = nbrs->next;
		i++;
	}
	quick_sort(stack, 0, len - 1);
	mid = stack[(len / 2)];
	free(stack);
	return (mid);
}

int	check_valid_rra(t_list *A, t_list *B)
{
	if (*(int *)ft_lstlast(A)->content > *(int *)A->content
		&& *(int *)ft_lstlast(A)->content > (*(int *)B->content))
		return (0);
	else if (*(int *)ft_lstlast(A)->content < *(int *)A->content
		&& *(int *)ft_lstlast(A)->content < (*(int *)B->content))
		return (0);
	return (1);
}

void	align_and_push_a(t_list **stack_a, t_list **stack_b, int len)
{
	if (len <= 25)
	{
		while (check_valid_rra(*stack_a, *stack_b))
			r_rotate_a(stack_a);
		while ((*(int *)(*stack_a)->content < (*(int *)(*stack_b)->content)))
			rotate_a(stack_a);
	}
	push_a(stack_b, stack_a);
}

void	check_r_rotate_ab(t_list **stack_a, t_list **stack_b, int len, int rrb)
{
	int	max;

	max = get_max(*stack_a);
	while ((check_valid_rra(*stack_a, *stack_b)
			|| *(int *)ft_lstlast(*stack_a)->content != max)
		&& (ft_lstsize(*stack_b) > len && rrb-- > 0))
		r_rotate_ab(stack_a, stack_b);
	while (check_valid_rra(*stack_a, *stack_b)
		|| *(int *)ft_lstlast(*stack_a)->content != max)
		r_rotate_a(stack_a);
	while (ft_lstsize(*stack_b) > len && rrb-- > 0)
		r_rotate_b(stack_b);
}

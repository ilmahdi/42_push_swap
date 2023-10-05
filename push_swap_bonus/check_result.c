/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_result.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:08:03 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:08:19 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	a_is_sorted(t_list *ls)
{
	while (ls->next)
	{
		if (*(int *)ls->content > *(int *)ls->next->content)
			return (0);
		ls = ls->next;
	}
	return (1);
}

void	check_result(t_list *stack_a, t_list *stack_b)
{
	if (a_is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

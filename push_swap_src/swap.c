/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:26:20 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:26:22 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	swap_a(t_list *list)
{
	swap(list);
	ft_putendl_fd("sa", 1);
}

void	swap_b(t_list *list)
{
	swap(list);
	ft_putendl_fd("sb", 1);
}

void	swap_ab(t_list *list_a, t_list *list_b)
{
	swap(list_a);
	swap(list_b);
	ft_putendl_fd("ss", 1);
}

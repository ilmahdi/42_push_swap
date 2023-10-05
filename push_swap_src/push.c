/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 15:32:58 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:24:45 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	push_a(t_list **nbr_o, t_list **nbr_n)
{
	push(nbr_o, nbr_n);
	ft_putendl_fd("pa", 1);
}

void	push_b(t_list **nbr_o, t_list **nbr_n)
{
	push(nbr_o, nbr_n);
	ft_putendl_fd("pb", 1);
}

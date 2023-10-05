/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:10 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:25:14 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	r_rotate_a(t_list **nbr)
{
	r_rotate(nbr);
	ft_putendl_fd("rra", 1);
}

void	r_rotate_b(t_list **nbr)
{
	r_rotate(nbr);
	ft_putendl_fd("rrb", 1);
}

void	r_rotate_ab(t_list **nbr_a, t_list **nbr_b)
{
	r_rotate(nbr_a);
	r_rotate(nbr_b);
	ft_putendl_fd("rrr", 1);
}

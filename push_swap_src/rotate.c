/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:25:49 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:25:52 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"

void	rotate_a(t_list **nbr)
{
	rotate(nbr);
	ft_putendl_fd("ra", 1);
}

void	rotate_b(t_list **nbr)
{
	rotate(nbr);
	ft_putendl_fd("rb", 1);
}

void	rotate_ab(t_list **nbr_a, t_list **nbr_b)
{
	rotate(nbr_a);
	rotate(nbr_b);
	ft_putendl_fd("rr", 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:23:03 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:23:36 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "./push_swap.h"

void	swap_a(t_list *list);
void	swap_b(t_list *list);
void	swap_ab(t_list *list_a, t_list *list_b);

void	push_a(t_list **nbr_o, t_list **nbr_n);
void	push_b(t_list **nbr_o, t_list **nbr_n);

void	rotate_a(t_list **nbr);
void	rotate_b(t_list **nbr);
void	rotate_ab(t_list **nbr_a, t_list **nbr_b);

void	r_rotate_a(t_list **nbr);
void	r_rotate_b(t_list **nbr);
void	r_rotate_ab(t_list **nbr_a, t_list **nbr_b);

#endif

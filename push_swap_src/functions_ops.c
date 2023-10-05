/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:20:11 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 11:33:47 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *nbr)
{
	if (!nbr || !nbr->next)
		return ;
	*(int *)nbr->content ^= *(int *)nbr->next->content;
	*(int *)nbr->next->content ^= *(int *)nbr->content;
	*(int *)nbr->content ^= *(int *)nbr->next->content;
}

void	push(t_list **nbr_o, t_list **nbr_n)
{
	t_list	*hol;

	if (!*nbr_o)
		return ;
	hol = (*nbr_o)->next;
	(*nbr_o)->next = (*nbr_n);
	ft_lstadd_front(nbr_n, *nbr_o);
	*nbr_o = hol;
}

void	rotate(t_list **nbr)
{
	t_list	*hol;

	if (!*nbr || !(*nbr)->next)
		return ;
	ft_lstlast(*nbr)->next = *nbr;
	hol = *nbr;
	*nbr = (*nbr)->next;
	hol->next = NULL;
}

void	r_rotate(t_list **nbr)
{
	t_list	*hol;
	t_list	*map;

	if (!*nbr || !(*nbr)->next)
		return ;
	hol = ft_lstlast(*nbr);
	map = *nbr;
	while (map->next != hol)
		map = map->next;
	map->next = NULL;
	hol->next = *nbr;
	*nbr = hol;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:00:10 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/06 18:21:51 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_nbrs(int *a, int *b)
{
	if (*a == *b)
		return ;
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

int	partition(int *a, int i, int j)
{
	int	p;
	int	m;
	int	k;

	p = a[i];
	m = i;
	k = i + 1;
	while (k <= j)
	{
		if (a[k] < p)
		{
			m++;
			swap_nbrs(&a[k], &a[m]);
		}
		k++;
	}
	swap_nbrs(&a[i], &a[m]);
	return (m);
}

void	quick_sort(int *a, int low, int high)
{
	int	piv;

	piv = partition(a, low, high);
	if (low < high)
	{
		quick_sort(a, low, piv);
		quick_sort(a, piv + 1, high);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:18:24 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:19:15 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_exit(t_collect *var)
{
	if (var->nbrs)
		free(var->nbrs);
	ft_lstclear(var->ls->stack_a, NULL);
	ft_lstclear(var->ls->stack_b, NULL);
	ft_putendl_fd("Error", 2);
	exit(0);
}

int	is_space(const char *av)
{
	int	i;

	i = 0;
	while (av[i] == ' ' || av[i] == '\t' || av[i] == '\n' || av[i] == '\v'
		|| av[i] == '\f' || av[i] == '\r')
		i++;
	return (i);
}

int	stack_len(char **av)
{
	int		i;
	int		j;
	int		ac;
	long	hol;

	i = 0;
	ac = 0;
	while (av[++i])
	{
		j = 0;
		if (!av[i][j])
			return (ft_putendl_fd("Error", 2), exit(0), 0);
		while (av[i][j])
		{
			j += is_space(&av[i][j]);
			if (!av[i][j])
				return (ft_putendl_fd("Error", 2), exit(0), 0);
			hol = ft_atoi_modified(&av[i][j], &j);
			if (hol > INT_MAX)
				return (ft_putendl_fd("Error", 2), exit(0), 0);
			j += is_space(&av[i][j]);
			ac++;
		}
	}
	return (ac);
}

long	ft_atoi_modified(const char *str, int *cmp)
{
	int		iden;
	int		s;
	long	i;
	long	res;

	iden = 0;
	s = 1;
	res = 0;
	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (*cmp)++ >= 0)
		if (str[i++] == '-')
			s *= -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (10 * res) + (str[i++] - '0');
		iden = 1;
		(*cmp)++;
	}
	res = res * s;
	if (iden == 0 || res > INT_MAX || res < INT_MIN)
		return ((long)INT_MAX + 1);
	return (res);
}

int	check_duplicate(int *nbrs, int len)
{
	int	*hol_nbrs;
	int	i;

	hol_nbrs = (int *)malloc((size_t)(len * sizeof(int)));
	if (!hol_nbrs)
		return (0);
	i = 0;
	while (i < len)
	{
		hol_nbrs[i] = nbrs[i];
		i++;
	}
	quick_sort(hol_nbrs, 0, len - 1);
	i = 0;
	while (i < (len - 1))
	{
		if (hol_nbrs[i] == hol_nbrs[i + 1])
			return (free(hol_nbrs), 0);
		i++;
	}
	return (free(hol_nbrs), 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:09:24 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:10:46 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	build_stacks(t_stacks *ls, int len, t_collect *var)
{
	int		i;
	t_list	*hol;

	i = 0;
	*ls->stack_a = ft_lstnew(&var->nbrs[i]);
	if (!*ls->stack_a)
		free_and_exit(var);
	while (--len)
	{
		hol = ft_lstnew(&var->nbrs[++i]);
		if (!hol)
			free_and_exit(var);
		ft_lstadd_back(ls->stack_a, hol);
	}
	*ls->stack_b = NULL;
}

void	init_stacks(t_stacks *ls, char **av, int len, t_collect *var)
{
	int	i;
	int	j;
	int	l;

	i = 0;
	l = 0;
	var->nbrs = (int *)malloc(len * sizeof(int));
	if (!var->nbrs)
		free_and_exit(var);
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			j += is_space(&av[i][j]);
			var->nbrs[l++] = (int)ft_atoi_modified(&av[i][j], &j);
			j += is_space(&av[i][j]);
		}
	}
	if (!check_duplicate(var->nbrs, len))
		free_and_exit(var);
	build_stacks(ls, l, var);
}

int	main(int ac, char **av)
{
	t_stacks	ls;
	t_list		*stack_a;
	t_list		*stack_b;
	t_collect	var;
	char		*ops;

	if (ac <= 1)
		return (0);
	ac = stack_len(av);
	ls = (t_stacks){&stack_a, &stack_b};
	var = (t_collect){NULL, &ls};
	init_stacks(&ls, av, ac, &var);
	ops = get_next_line(0);
	while (ops)
	{
		execute_ops(ops, &stack_a, &stack_b, &var);
		free(ops);
		ops = get_next_line(0);
	}
	check_result(stack_a, stack_b);
	free(var.nbrs);
	ft_lstclear(&stack_a, NULL);
	ft_lstclear(&stack_b, NULL);
	return (free(ops), 0);
}

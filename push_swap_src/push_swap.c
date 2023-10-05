/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:14:03 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 11:16:42 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	if (ac <= 1)
		return (0);
	ac = stack_len(av);
	ls = (t_stacks){&stack_a, &stack_b};
	var = (t_collect){NULL, &ls};
	init_stacks(&ls, av, ac, &var);
	if (ac < 4)
		sort_stack_three(&stack_a, ac);
	else if (ac < 6)
		sort_stack_five(&ls, ac, &var);
	else
		sort_stack_a(&ls, get_max(stack_a), ac, &var);
	free(var.nbrs);
	ft_lstclear(&stack_a, NULL);
	return (0);
}

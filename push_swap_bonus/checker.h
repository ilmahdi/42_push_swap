/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 12:11:26 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 12:13:47 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define ORDER_STACK_A 1
# define ORDER_STACK_B 2

typedef struct s_stacks
{
	t_list	**stack_a;
	t_list	**stack_b;
}	t_stacks;

typedef struct s_collect
{
	int			*nbrs;
	t_stacks	*ls;
}	t_collect;

void	swap(t_list *nbr);
void	rotate(t_list **nbr);
void	r_rotate(t_list **nbr);
void	push(t_list **nbr_o, t_list **nbr_n);

void	execute_ops(char *ops, t_list **stk_a, t_list **stk_b, t_collect *var);
void	check_result(t_list *stack_a, t_list *stack_b);

char	*get_next_line(int fd);
long	ft_atoi_modified(const char *str, int *cmp);
void	free_and_exit(t_collect *var);
int		check_duplicate(int *nbrs, int len);
int		is_space(const char *av);
int		stack_len(char **av);
void	quick_sort(int *a, int low, int high);

#endif

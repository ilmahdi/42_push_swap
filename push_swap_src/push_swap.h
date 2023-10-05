/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabdelha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 11:37:11 by eabdelha          #+#    #+#             */
/*   Updated: 2022/01/18 11:41:45 by eabdelha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "./operations.h"
# include <stdlib.h>
# include <unistd.h>

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

long	ft_atoi_modified(const char *str, int *cmp);
void	free_and_exit(t_collect *var);
int		check_duplicate(int *nbrs, int len);
int		is_space(const char *av);
int		stack_len(char **av);

void	quick_sort(int *a, int low, int high);

void	sort_stack_a(t_stacks *ls, int max, int len, t_collect *var);
void	sort_stack_b(t_stacks *ls, int max, int len, t_collect *var);

void	sort_stack_three(t_list **stack_a, int len);
void	sort_stack_five(t_stacks *ls, int len, t_collect *var);

int		get_max(t_list *stack_a);
int		get_mid(t_list *nbrs, int len, t_collect *var);
int		ab_is_sorted(t_list *ls, int len, int order);

int		check_valid_rra(t_list *A, t_list *B);
void	align_and_push_a(t_list **stack_a, t_list **stack_b, int len);
void	check_r_rotate_ab(t_list **stack_a, t_list **stack_b, int len, int rra);

#endif

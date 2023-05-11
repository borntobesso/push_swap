/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:39:44 by sojung            #+#    #+#             */
/*   Updated: 2022/01/20 12:15:04 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_info
{
	int	stack_size;
	int	top_a;
	int	top_b;
	int	*stack_a;
	int	*stack_b;
}	t_info;

typedef struct s_pivot
{
	int	pivot1;
	int	pivot2;
	int	pb1;
	int	pb2;
}	t_pivot;

typedef struct s_list
{
	char			*ops;
	struct s_list	*next;
}	t_list;

/***	initializing functions (ft_init.c)	***/
int				*ft_init_a(int size, char **args);
int				*ft_init_b(int size);
t_info			*ft_init_info(t_info *stack_info, int size, char **args);

/***	arguments verifying functions (arg_utils.c)	***/
int				ft_isdigit(char c);
int				count_l(char *s);
int				check_double_arg(int pos, char **argv);
long long int	ft_atoi(const char *s);
void			check_valid_args(int argc, char **argv, t_info *stack_info);

/***	error utilities (error_case.c)	***/
void			error_case(int i, t_info *stack_info);
void			is_sorted(t_info *stack_info);

/***	main (push_swap.c) 	***/
void			print_arr(t_info *stack_info);

/***	index utilities (utils.c)	***/
int				ft_min_index(int *stack, int size);
int				ft_max_index(int *stack, int size);
int				srch_index(int b, t_info *stack_info);
int				srch_pivot(int *stack, int top_index, int n);

/***	3 and 5 elements functions (little_sort.c)	***/
void			sort_3(t_info *stack_info);
void			sort_5(t_info *stack_info);

/***	calculating movements (mov_utils.c)	***/
int				ft_abs(int value);
int				count_mov(int top_index, int index);
int				calcul_mov(t_info *stack_info, int index_b);
int				srch_min_mov(t_info *stack_info, int pivot);

/***	first pivot move functions (pivot_utils.c)	***/
void			a_to_b(t_info *stack_info, int index, int *count_pb);
int				srch_top(t_info *stack_info, int pivot);
int				srch_bot(t_info *stack_info, int pivot);
void			srch_and_move(t_info *stack_info, int pivot, int *count_pb);
void			pivot_sort(t_info *stack_info, t_pivot *pivot_info);

/***	action functions (ft_action.c)	***/
void			two_dir_r(t_info *stack_info, int mov_a, int mov_b);
void			action_pos(t_info *stack_info, int mov_a, int mov_b);
void			action_neg(t_info *stack_info, int mov_a, int mov_b);
void			action_b(t_info *stack_info, int index_b);

/***	big elements functions (big_sort.c)	***/
void			rotate_top(t_info *stack_info);
void			rep_action_b(t_info *stack_info, int n, int pivot);
void			big_sort(t_info *stack_info);

/***	push and swap functions (ft_ps.c)	***/
void			sa(t_info *stack_info);
void			sb(t_info *stack_info);
void			ss(t_info *stack_info);
void			pa(t_info *stack_info);
void			pb(t_info *stack_info);

/***	rotate functions (ft_r.c)	***/
void			ra(t_info *stack_info);
void			rb(t_info *stack_info);
void			rr(t_info *stack_info);

/***	reverse rotate fuctions (ft_rr.c)	***/
void			rra(t_info *stack_info);
void			rrb(t_info *stack_info);
void			rrr(t_info *stack_info);

/***	checker push and swap functions (ft_ps_checker.c)	***/
void			sa_ch(t_info *stack_info);
void			sb_ch(t_info *stack_info);
void			ss_ch(t_info *stack_info);
void			pa_ch(t_info *stack_info);
void			pb_ch(t_info *stack_info);

/***	checker rotate functions (ft_r_checker.c)	***/
void			ra_ch(t_info *stack_info);
void			rb_ch(t_info *stack_info);
void			rr_ch(t_info *stack_info);

/***	checker reverse rotate fuctions (ft_rr_checker.c)	***/
void			rra_ch(t_info *stack_info);
void			rrb_ch(t_info *stack_info);
void			rrr_ch(t_info *stack_info);

/***	checker init fuctions (checker_init.c)	***/
int				*stack_a_dup(t_info *stack_info, t_info *stack_dup);
int				*stack_b_dup(t_info *stack_dup);
void			ft_dup_info(t_info *stack_info, t_info *stack_dup);

/***	checker split functions (checker_split.c)	***/
int				ops_count(char const *s);
char			*ops_malloc(char const *s);
void			ft_free_split(char **res, int index, t_info *stack);
char			**ft_split(char const *s, t_info *stack_info);

/***	checker utility fuctions (checker_utils.c)	***/
int				ft_strcmp(char *s1, char *s2);
void			do_ops_ps(char *ops, t_info *stack_info);
void			do_ops_r(char *ops, t_info *stack_info);
void			do_ops(char **ops, t_info *stack_info);
void			ft_free(t_info *stack_info);

/***	checker result print function (checker.c)	***/
int				is_sorted_checker(t_info *stack_dup);
void			ft_free_ops(char **ops);
void			print_res(t_info *stack_info);

/***	checker ops list (checker_list.c)	***/
t_list			*ft_lstnew(char *ops);
void			ft_lstadd_back(t_list **lst, t_list *new);
char			*ft_strdup(char *s);
void			do_op(t_list *ops_lst, t_info *stack_dup);

#endif

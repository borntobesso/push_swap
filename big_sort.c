/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:33:43 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 18:05:53 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_top(t_info *stack_info)
{
	int	min_index;
	int	mov;
	int	i;

	min_index = ft_min_index(stack_info->stack_a, stack_info->top_a + 1);
	mov = count_mov(stack_info->top_a, min_index);
	i = 0;
	while (i < ft_abs(mov))
	{
		if (mov < 0)
			rra(stack_info);
		else
			ra(stack_info);
		i++;
	}
}

void	rep_action_b(t_info *stack_info, int n, int pivot)
{
	int	i;

	i = 0;
	while (i < n)
	{
		action_b(stack_info, srch_min_mov(stack_info, pivot));
		i++;
	}
	rotate_top(stack_info);
}

void	big_sort(t_info *stack_info)
{
	int		min_index;
	int		min_val;
	int		n;
	t_pivot	pivot_info;

	pivot_info.pb1 = 0;
	pivot_info.pb2 = 0;
	pivot_sort(stack_info, &pivot_info);
	while (stack_info->top_a != -1)
		pb(stack_info);
	n = stack_info->stack_size - pivot_info.pb1 - pivot_info.pb2;
	rep_action_b(stack_info, n, pivot_info.pivot2);
	rep_action_b(stack_info, pivot_info.pb2, pivot_info.pivot1);
	min_index = ft_min_index(stack_info->stack_b, stack_info->top_b + 1);
	min_val = stack_info->stack_b[min_index];
	rep_action_b(stack_info, pivot_info.pb1, min_val);
	pa(stack_info);
}

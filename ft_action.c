/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 11:51:50 by sojung            #+#    #+#             */
/*   Updated: 2022/01/17 11:51:56 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_dir_r(t_info *stack_info, int mov_a, int mov_b)
{
	int	i;

	i = 0;
	if (ft_abs(mov_a) > ft_abs(mov_b))
	{
		while (i++ < ft_abs(mov_b))
			rr(stack_info);
		i = 0;
		while (i++ < ft_abs(mov_a) - ft_abs(mov_b))
			ra(stack_info);
	}
	else
	{
		while (i++ < ft_abs(mov_a))
			rr(stack_info);
		i = 0;
		while (i++ < ft_abs(mov_b) - ft_abs(mov_a))
			rb(stack_info);
	}
}

void	action_pos(t_info *stack_info, int mov_a, int mov_b)
{
	int	i;

	i = 0;
	if (mov_a < 0 || mov_b < 0)
	{
		if (ft_abs(mov_a) > ft_abs(mov_b))
		{	
			while (i++ < ft_abs(mov_b))
				rrr(stack_info);
			i = 0;
			while (i++ < ft_abs(mov_a) - ft_abs(mov_b))
				rra(stack_info);
		}
		else
		{
			while (i++ < ft_abs(mov_a))
				rrr(stack_info);
			i = 0;
			while (i++ < ft_abs(mov_b) - ft_abs(mov_a))
				rrb(stack_info);
		}
	}
	else
		two_dir_r(stack_info, mov_a, mov_b);
	pa(stack_info);
}

void	action_neg(t_info *stack_info, int mov_a, int mov_b)
{
	int	i;

	i = 0;
	while (i++ < ft_abs(mov_a))
	{
		if (mov_a < 0)
			rra(stack_info);
		else
			ra(stack_info);
	}
	i = 0;
	while (i++ < ft_abs(mov_b))
	{
		if (mov_b < 0)
			rrb(stack_info);
		else
			rb(stack_info);
	}
	pa(stack_info);
}

void	only_b(t_info *stack_info, int mov_b)
{
	int	i;

	i = 0;
	while (i < ft_abs(mov_b))
	{
		if (mov_b < 0)
			rrb(stack_info);
		else
			rb(stack_info);
		i++;
	}
	pa(stack_info);
	sa(stack_info);
}

void	action_b(t_info *stack_info, int index_b)
{
	int	index_a;
	int	mov_a;
	int	mov_b;

	index_a = srch_index(stack_info->stack_b[index_b], stack_info);
	mov_a = count_mov(stack_info->top_a, index_a);
	mov_b = count_mov(stack_info->top_b, index_b);
	if (stack_info->top_a == 0 && index_a == 0)
		only_b(stack_info, mov_b);
	else if (mov_a * mov_b >= 0)
		action_pos(stack_info, mov_a, mov_b);
	else
		action_neg(stack_info, mov_a, mov_b);
}

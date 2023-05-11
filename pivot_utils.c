/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:45:20 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 18:05:28 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	a_to_b(t_info *stack_info, int index, int *count_pb)
{
	int	i;

	i = 0;
	if (index >= (stack_info->top_a + 1) / 2)
		while (i++ < stack_info->top_a - index)
			ra(stack_info);
	else
		while (i++ < index + 1)
			rra(stack_info);
	pb(stack_info);
	(*count_pb)++;
}

int	srch_top(t_info *stack_info, int pivot)
{
	int	i;

	i = stack_info->top_a;
	while (i >= 0)
	{
		if (stack_info->stack_a[i] <= pivot)
			return (i);
		i--;
	}
	return (-1);
}

int	srch_bot(t_info *stack_info, int pivot)
{
	int	i;

	i = 0;
	while (i <= (stack_info->top_a))
	{
		if (stack_info->stack_a[i] <= pivot)
			return (i);
		i++;
	}
	return (-1);
}

void	srch_and_move(t_info *stack_info, int pivot, int *count_pb)
{
	int	top_el;
	int	bot_el;
	int	count_top;
	int	count_bot;

	while (1)
	{
		top_el = srch_top(stack_info, pivot);
		bot_el = srch_bot(stack_info, pivot);
		if (top_el != -1 && bot_el != -1)
		{
			count_top = count_mov(stack_info->top_a, top_el);
			count_bot = count_mov(stack_info->top_a, bot_el);
			if (ft_abs(count_top) < ft_abs(count_bot))
				a_to_b(stack_info, top_el, count_pb);
			else
				a_to_b(stack_info, bot_el, count_pb);
		}
		else
			break ;
	}
}

void	pivot_sort(t_info *stack_info, t_pivot *pivot_info)
{
	pivot_info->pivot1 = srch_pivot(stack_info->stack_a, stack_info->top_a, 2);
	srch_and_move(stack_info, pivot_info->pivot1, &pivot_info->pb1);
	pivot_info->pivot2 = srch_pivot(stack_info->stack_a, stack_info->top_a, 2);
	srch_and_move(stack_info, pivot_info->pivot2, &pivot_info->pb2);
}

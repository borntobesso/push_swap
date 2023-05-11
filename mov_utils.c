/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mov_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:38:12 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:28:15 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int value)
{
	if (value < 0)
		return (value * -1);
	else
		return (value);
}

int	count_mov(int top_index, int index)
{
	if (index >= ((top_index + 1) / 2))
		return (top_index - index);
	else
		return (-1 * (index + 1));
}

int	calcul_mov(t_info *stack_info, int index_b)
{
	int	index_a;
	int	mov_a;
	int	mov_b;

	index_a = srch_index(stack_info->stack_b[index_b], stack_info);
	mov_a = count_mov(stack_info->top_a, index_a);
	mov_b = count_mov(stack_info->top_b, index_b);
	if (mov_a * mov_b < 0)
		return (ft_abs(mov_a) + ft_abs(mov_b));
	else
	{
		if (ft_abs(mov_a) > ft_abs(mov_b))
			return (ft_abs(mov_a));
		else
			return (ft_abs(mov_b));
	}
}

int	srch_min_mov(t_info *stack_info, int pivot)
{
	int	i;
	int	min_index;
	int	min_mov;

	i = stack_info->top_b;
	min_index = i;
	min_mov = 5000;
	while (i >= 0)
	{
		if (stack_info->stack_b[i] > pivot)
		{
			if (calcul_mov(stack_info, i) < min_mov)
			{
				min_mov = calcul_mov(stack_info, i);
				min_index = i;
			}
		}
		i--;
	}
	return (min_index);
}

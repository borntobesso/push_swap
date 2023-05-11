/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:01:06 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:29:07 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_index(int *stack, int size)
{
	int	min_index;
	int	i;

	i = 0;
	min_index = 0;
	while (i < size)
	{
		if (stack[min_index] > stack[i])
			min_index = i;
		i++;
	}
	return (min_index);
}

int	ft_max_index(int *stack, int size)
{
	int	max_index;
	int	i;

	i = 0;
	max_index = 0;
	while (i < size)
	{
		if (stack[max_index] < stack[i])
			max_index = i;
		i++;
	}
	return (max_index);
}

int	srch_index(int b, t_info *stack_info)
{
	int	i;

	i = 0;
	if (stack_info->top_a == -1)
		return (0);
	while (i < stack_info->top_a)
	{
		if (b < stack_info->stack_a[i] && b > stack_info->stack_a[i + 1])
			return (i);
		i++;
	}
	if (b < stack_info->stack_a[i] && b > stack_info->stack_a[0])
		return (i);
	i = 0;
	while (i < stack_info->top_a)
	{
		if (stack_info->stack_a[i] < stack_info->stack_a[i + 1])
			return (i);
		i++;
	}
	return (i);
}

int	srch_pivot(int *stack, int top_index, int n)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	while (i < top_index + 1)
	{
		j = 0;
		count = 0;
		while (j < top_index + 1)
		{
			if (stack[i] > stack[j])
				count++;
			j++;
		}
		if (count == (top_index / n))
			return (stack[i]);
		i++;
	}
	return (stack[0]);
}

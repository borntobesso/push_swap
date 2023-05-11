/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:15:13 by sojung            #+#    #+#             */
/*   Updated: 2022/01/15 14:13:40 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_info *stack_info)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack_info->top_a == 0 || stack_info->top_a == -1)
		return ;
	while (i < stack_info->top_a)
	{
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i + 1];
		stack_info->stack_a[i + 1] = tmp;
		i++;
	}
	write(1, "rra\n", 4);
}

void	rrb(t_info *stack_info)
{
	int	tmp;
	int	i;

	i = 0;
	if (stack_info->top_b == 0 || stack_info->top_b == 0)
		return ;
	while (i < stack_info->top_b)
	{
		tmp = stack_info->stack_b[i];
		stack_info->stack_b[i] = stack_info->stack_b[i + 1];
		stack_info->stack_b[i + 1] = tmp;
		i++;
	}
	write(1, "rrb\n", 4);
}

void	rrr(t_info *stack_info)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < stack_info->top_a)
	{
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i + 1];
		stack_info->stack_a[i + 1] = tmp;
		i++;
	}
	j = 0;
	while (j < stack_info->top_b)
	{
		tmp = stack_info->stack_b[j];
		stack_info->stack_b[j] = stack_info->stack_b[j + 1];
		stack_info->stack_b[j + 1] = tmp;
		j++;
	}
	write(1, "rrr\n", 4);
}

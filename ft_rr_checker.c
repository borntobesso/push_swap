/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rr_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:39:21 by sojung            #+#    #+#             */
/*   Updated: 2022/01/17 17:11:40 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra_ch(t_info *stack_info)
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
}

void	rrb_ch(t_info *stack_info)
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
}

void	rrr_ch(t_info *stack_info)
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
}

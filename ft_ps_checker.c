/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:33:51 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:27:22 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_ch(t_info *stack_info)
{
	int	tmp;
	int	i;

	i = stack_info->top_a;
	if (i > 0)
	{
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i - 1];
		stack_info->stack_a[i - 1] = tmp;
	}
}

void	sb_ch(t_info *stack_info)
{
	int	tmp;
	int	i;

	i = stack_info->top_b;
	if (i > 0)
	{
		tmp = stack_info->stack_b[i];
		stack_info->stack_b[i] = stack_info->stack_b[i - 1];
		stack_info->stack_b[i - 1] = tmp;
	}
}

void	ss_ch(t_info *stack_info)
{
	int	tmp;
	int	i;
	int	j;

	i = stack_info->top_a;
	j = stack_info->top_b;
	if (i > 0)
	{
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i - 1];
		stack_info->stack_a[i - 1] = tmp;
	}
	if (j > 0)
	{
		tmp = stack_info->stack_b[j];
		stack_info->stack_b[j] = stack_info->stack_b[j - 1];
		stack_info->stack_b[j - 1] = tmp;
	}
}

void	pa_ch(t_info *stack_info)
{
	int	tmp;

	if (stack_info->top_b != -1)
	{
		tmp = stack_info->stack_b[stack_info->top_b];
		stack_info->stack_a[stack_info->top_a + 1] = tmp;
		stack_info->stack_b[stack_info->top_b] = 0;
		stack_info->top_a += 1;
		stack_info->top_b -= 1;
	}
}

void	pb_ch(t_info *stack_info)
{
	int	tmp;

	if (stack_info->top_a != -1)
	{
		tmp = stack_info->stack_a[stack_info->top_a];
		stack_info->stack_b[stack_info->top_b + 1] = tmp;
		stack_info->stack_a[stack_info->top_a] = 0;
		stack_info->top_b += 1;
		stack_info->top_a -= 1;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:38:10 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:27:47 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra_ch(t_info *stack_info)
{
	int	i;
	int	tmp;

	i = stack_info->top_a;
	if (i == 0 || i == -1)
		return ;
	while (i > 0)
	{
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i - 1];
		stack_info->stack_a[i - 1] = tmp;
		i--;
	}
}

void	rb_ch(t_info *stack_info)
{
	int	i;
	int	tmp;

	i = stack_info->top_b;
	if (i == 0 || i == -1)
		return ;
	while (i > 0)
	{
		tmp = stack_info->stack_b[i];
		stack_info->stack_b[i] = stack_info->stack_b[i - 1];
		stack_info->stack_b[i - 1] = tmp;
		i--;
	}
}

void	rr_ch(t_info *stack_info)
{
	int	i;
	int	j;
	int	tmp;

	i = stack_info->top_a;
	j = stack_info->top_b;
	while (i > 0)
	{
		if (i == 0)
			break ;
		tmp = stack_info->stack_a[i];
		stack_info->stack_a[i] = stack_info->stack_a[i - 1];
		stack_info->stack_a[i - 1] = tmp;
		i--;
	}
	while (j > 0)
	{
		if (j == 0)
			break ;
		tmp = stack_info->stack_b[j];
		stack_info->stack_b[j] = stack_info->stack_b[j - 1];
		stack_info->stack_b[j - 1] = tmp;
		j--;
	}
}

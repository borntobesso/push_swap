/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_r.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:14:50 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:08:57 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_info *stack_info)
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
	write(1, "ra\n", 3);
}

void	rb(t_info *stack_info)
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
	write(1, "rb\n", 3);
}

void	rr(t_info *stack_info)
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
	write(1, "rr\n", 3);
}

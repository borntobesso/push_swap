/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:14:14 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:08:14 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_info *stack_info)
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
	write(1, "sa\n", 3);
}

void	sb(t_info *stack_info)
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
	write(1, "sb\n", 3);
}

void	ss(t_info *stack_info)
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
	write(1, "ss\n", 3);
}

void	pa(t_info *stack_info)
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
	write(1, "pa\n", 3);
}

void	pb(t_info *stack_info)
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
	write(1, "pb\n", 3);
}

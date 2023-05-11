/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:06:35 by sojung            #+#    #+#             */
/*   Updated: 2022/01/17 19:57:20 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*stack_a_dup(t_info *stack_info, t_info *stack_dup)
{
	int	*stack_a;
	int	i;

	stack_a = malloc(sizeof(int) * stack_dup->stack_size);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < stack_dup->stack_size)
	{
		stack_a[i] = stack_info->stack_a[i];
		i++;
	}
	return (stack_a);
}

int	*stack_b_dup(t_info *stack_dup)
{
	int	*stack_b;
	int	i;

	stack_b = malloc(sizeof(int) * stack_dup->stack_size);
	if (!stack_b)
		return (NULL);
	i = 0;
	while (i < stack_dup->stack_size)
	{
		stack_b[i] = 0;
		i++;
	}
	return (stack_b);
}

void	ft_dup_info(t_info *stack_info, t_info *stack_dup)
{
	stack_dup->stack_size = stack_info->stack_size;
	stack_dup->top_a = stack_info->top_a;
	stack_dup->top_b = -1;
	stack_dup->stack_a = stack_a_dup(stack_info, stack_dup);
	stack_dup->stack_b = stack_b_dup(stack_dup);
}

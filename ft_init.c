/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 17:15:29 by sojung            #+#    #+#             */
/*   Updated: 2022/01/17 19:57:16 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_init_a(int size, char **args)
{
	int	*stack_a;
	int	i;

	stack_a = malloc(sizeof(int) * size);
	if (!stack_a)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack_a[size - 1 - i] = (int)ft_atoi(args[i]);
		i++;
	}
	return (stack_a);
}

int	*ft_init_b(int size)
{
	int	*stack_b;
	int	i;

	stack_b = malloc(sizeof(int) * size);
	if (!stack_b)
		return (NULL);
	i = 0;
	while (i < size)
	{
		stack_b[i] = 0;
		i++;
	}
	return (stack_b);
}

t_info	*ft_init_info(t_info *stack_info, int size, char **argv)
{
	stack_info->stack_size = size;
	stack_info->top_a = size - 1;
	stack_info->top_b = -1;
	stack_info->stack_a = ft_init_a(size, argv);
	stack_info->stack_b = ft_init_b(size);
	return (stack_info);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:53:47 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:07:01 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_case(int i, t_info *stack_info)
{
	if (i == 1)
		write(STDERR_FILENO, "Error\n", 6);
	else if (i == 0)
	{
		free(stack_info->stack_a);
		free(stack_info->stack_b);
	}
	exit (0);
}

void	is_sorted(t_info *stack_info)
{
	int	i;
	int	size;
	int	*a;

	size = stack_info->stack_size;
	a = stack_info->stack_a;
	if (a == NULL || size <= 1)
		error_case(0, stack_info);
	i = 0;
	while (i < size - 1)
	{
		if (a[i] < a[i + 1])
			return ;
		i++;
	}
	error_case(0, stack_info);
}

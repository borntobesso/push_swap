/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:28:50 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 16:41:46 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_info *stack_info)
{
	int	*a;

	a = stack_info->stack_a;
	if (a[0] > a[1] && a[1] > a[2])
		return ;
	else if (ft_max_index(a, 3) == 0 || ft_min_index(a, 3) == 2 || \
		((ft_min_index(a, 3) == 0) && (ft_max_index(a, 3) == 2)))
		sa(stack_info);
	else if ((ft_max_index(a, 3) == 2) && (ft_min_index(a, 3) == 1))
		ra(stack_info);
	else if ((ft_max_index(a, 3) == 1) && (ft_min_index(a, 3) == 0))
		rra(stack_info);
	sort_3(stack_info);
}

void	sort_5(t_info *stack_info)
{
	int	pivot;
	int	i;

	pivot = srch_pivot(stack_info->stack_a, stack_info->top_a, 2);
	i = 0;
	while (i < stack_info->stack_size + 1)
	{
		if (stack_info->stack_a[stack_info->top_a] < pivot)
			pb(stack_info);
		else
			ra(stack_info);
		i++;
	}
	sort_3(stack_info);
	if (stack_info->stack_b[0] > stack_info->stack_b[1])
		sb(stack_info);
	pa(stack_info);
	pa(stack_info);
}

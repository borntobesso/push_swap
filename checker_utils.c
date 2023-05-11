/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:23:01 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:23:44 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	ft_free(t_info *stack_info)
{
	free(stack_info->stack_a);
	free(stack_info->stack_b);
}

void	do_ops_ps(char *ops, t_info *stack_info)
{
	if (ft_strcmp(ops, "pa") == 0)
		pa_ch(stack_info);
	else if (ft_strcmp(ops, "pb") == 0)
		pb_ch(stack_info);
	else if (ft_strcmp(ops, "sa") == 0)
		sa_ch(stack_info);
	else if (ft_strcmp(ops, "sb") == 0)
		sb_ch(stack_info);
	else if (ft_strcmp(ops, "ss") == 0)
		ss_ch(stack_info);
}

void	do_ops_r(char *ops, t_info *stack_info)
{
	if (ft_strcmp(ops, "ra") == 0)
		ra_ch(stack_info);
	else if (ft_strcmp(ops, "rb") == 0)
		rb_ch(stack_info);
	else if (ft_strcmp(ops, "rr") == 0)
		rr_ch(stack_info);
	else if (ft_strcmp(ops, "rra") == 0)
		rra_ch(stack_info);
	else if (ft_strcmp(ops, "rrb") == 0)
		rrb_ch(stack_info);
	else if (ft_strcmp(ops, "rrr") == 0)
		rrr_ch(stack_info);
}

void	do_ops(char **ops, t_info *stack_info)
{
	int	i;

	i = 0;
	while (ops[i] != 0)
	{
		if (ops[i][0] == 'p' || ops[i][0] == 's')
			do_ops_ps(ops[i], stack_info);
		else if (ops[i][0] == 'r')
			do_ops_r(ops[i], stack_info);
		i++;
	}
}

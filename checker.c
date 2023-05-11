/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:24:36 by sojung            #+#    #+#             */
/*   Updated: 2022/01/20 12:51:22 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted_checker(t_info *stack_dup)
{
	int	size;
	int	i;

	size = stack_dup->top_a;
	i = 0;
	while (i < size)
	{
		if (stack_dup->stack_a[i + 1] > stack_dup->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_ops(char **ops)
{
	int	i;

	i = 0;
	while (ops[i] != 0)
	{
		free(ops[i]);
		i++;
	}
	free(ops[i]);
	free(ops);
}

void	print_res(t_info *stack_info)
{
	if (is_sorted_checker(stack_info) && (stack_info->top_b == -1))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_free(stack_info);
}	

int	main(int argc, char **argv)
{
	t_info	stack_info;
	char	buf[40000];
	int		i;
	char	**ops;

	if (argc > 1)
	{
		check_valid_args(argc - 1, argv + 1, &stack_info);
		ft_init_info(&stack_info, argc - 1, argv + 1);
		is_sorted(&stack_info);
		i = read(0, buf, 39999);
		buf[i] = '\0';
		ops = ft_split(buf, &stack_info);
		do_ops(ops, &stack_info);
		ft_free_ops(ops);
		print_res(&stack_info);
	}
	return (0);
}

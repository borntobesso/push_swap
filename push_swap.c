/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 16:32:23 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 15:06:40 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_arr(t_info *stack_info)
{
	int	i;

	i = stack_info->stack_size - 1;
	while (i >= 0)
	{
		printf("%d %d\n", stack_info->stack_a[i], stack_info->stack_b[i]);
		i--;
	}	
	printf("- -\n");
	printf("a b\n");
}

int	main(int argc, char **argv)
{
	t_info	stack_info;

	if (argc > 1)
	{
		check_valid_args(argc - 1, argv + 1, &stack_info);
		ft_init_info(&stack_info, argc - 1, argv + 1);
		is_sorted(&stack_info);
		if (argc == 3)
			sa(&stack_info);
		else if (argc == 4)
			sort_3(&stack_info);
		else if (argc == 6)
			sort_5(&stack_info);
		else
			big_sort(&stack_info);
		free(stack_info.stack_a);
		free(stack_info.stack_b);
	}
	return (0);
}

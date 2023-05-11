/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:23:17 by sojung            #+#    #+#             */
/*   Updated: 2022/01/17 14:49:50 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	count_l(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	if (i > 11)
		return (1);
	else
		return (0);
}

int	check_double_arg(int pos, char **argv)
{
	int	i;

	i = 0;
	while (i < pos)
	{
		if (ft_atoi(argv[i]) == ft_atoi(argv[pos]))
			return (1);
		i++;
	}
	return (0);
}

long long int	ft_atoi(const char *s)
{
	long long int	sign;
	long long int	res;

	sign = 1;
	res = 0;
	while ((*s >= '\t' && *s <= '\r') || *s == ' ')
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - '0';
		s++;
	}
	return (sign * res);
}

void	check_valid_args(int argc, char **argv, t_info *stack_info)
{
	int	i;
	int	j;

	i = 0;
	while (i < argc)
	{
		if (argv == NULL || argv[i] == NULL)
			error_case(1, stack_info);
		j = 0;
		if (argv[i][0] == '+' || argv[i][0] == '-')
			j++;
		if (argv[i][j] == '\0')
			error_case(1, stack_info);
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error_case(1, stack_info);
			j++;
		}
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN || \
			(check_double_arg(i, argv) == 1) || count_l(argv[i]))
			error_case(1, stack_info);
		i++;
	}
}

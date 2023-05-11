/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 18:07:59 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:18:10 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ops_count(char const *s)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == '\n')
			s++;
		if (*s && *s != '\n')
		{
			count++;
			while (*s && *s != '\n')
				s++;
		}
	}
	return (count);
}

char	*ops_malloc(char const *s)
{
	int		len;
	int		i;
	char	*res;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s && *s != '\n')
	{
		res[i] = *s;
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}

void	ft_free_split(char **res, int index, t_info *stack_info)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(res[i]);
		i++;
	}
	free(res);
	ft_free(stack_info);
	exit (1);
}

char	**ft_split(char const *s, t_info *stack_info)
{
	int		size;
	char	**res;
	int		i;

	size = ops_count(s);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == '\n')
			s++;
		if (*s && *s != '\n')
		{
			res[i] = ops_malloc(s);
			if (res[i] == NULL)
				ft_free_split(res, i, stack_info);
			i++;
			while (*s && *s != '\n')
				s++;
		}
	}
	res[i] = 0;
	return (res);
}

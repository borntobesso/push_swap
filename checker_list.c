/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sojung <sojung@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 13:20:08 by sojung            #+#    #+#             */
/*   Updated: 2022/01/18 17:11:05 by sojung           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(char *ops)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->ops = ops;
	new->next = NULL;
	return (new);
}
// all the ops structs for free ! (lst_all_clear?)

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = *lst;
	if (last == NULL)
	{
		*lst = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\n')
		i++;
	if (i == 0)
		return (NULL);
	dup = malloc(sizeof(char) * (i + 1));
	j = 0;
	while (j < i)
	{
		dup[j] = s[j];
		j++;
	}
	dup[j] = '\0';
	return (dup);
}
//all the char *ops in the chained list for free !

void	do_op(t_list *ops_lst, t_info *stack_dup)
{
	t_list	*lst;

	lst = ops_lst;
	while (lst->next)
	{
		if (lst->ops[0] == 'p' || lst->ops[0] == 's')
			do_ops_ps(lst->ops, stack_dup);
		else if (lst->ops[0] == 'r')
			do_ops_r(lst->ops, stack_dup);
		lst = lst->next;
	}
	if (lst->ops[0] == 'p' || lst->ops[0] == 's')
		do_ops_ps(lst->ops, stack_dup);
	else if (lst->ops[0] == 'r')
		do_ops_r(lst->ops, stack_dup);
}

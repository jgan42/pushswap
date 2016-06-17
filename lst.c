/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:14:34 by jgan              #+#    #+#             */
/*   Updated: 2016/02/09 15:14:36 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*lst_new(int i)
{
	t_lst *elem;

	elem = (t_lst *)malloc(sizeof(t_lst));
	if (elem == NULL)
		return (NULL);
	elem->i = i;
	elem->next = NULL;
	return (elem);
}

t_lst	*lst_last(t_lst *start, int null)
{
	if (!start || (null < 0 && !start->next))
		return (NULL);
	while (start->next)
	{
		if (!null && !start->next->i)
			return (start);
		if (null < 0 && !start->next->next)
			return (null == -1 ? start : NULL);
		if (null == -2 && !start->next->next->next)
			return (start);
		start = start->next;
	}
	return (start);
}

int		lst_pushback(t_lst **start, t_lst *new)
{
	t_lst *tmp;

	tmp = *start;
	if (!new)
		return (0);
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*start = new;
	return (1);
}

int		lst_pushfront(t_lst **start, t_lst *new)
{
	if (!new)
		return (0);
	new->next = *start;
	*start = new;
	return (1);
}

int		lst_clear(t_lst **start)
{
	t_lst *tmp;
	t_lst *i;

	i = *start;
	if (i)
	{
		while (i->next)
		{
			tmp = i;
			i = i->next;
			free(tmp);
			tmp = NULL;
		}
		free(i);
		i = NULL;
		*start = NULL;
	}
	return (1);
}

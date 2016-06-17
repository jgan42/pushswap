/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/12 09:31:40 by jgan              #+#    #+#             */
/*   Updated: 2016/02/12 09:31:44 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ps_swap(t_ps *ps, char ab)
{
	t_lst	*tmp;
	t_lst	*prev;
	int		swap;

	tmp = (ab == 'a' ? ps->a : ps->b);
	if (!tmp || !tmp->next)
		return (0);
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	swap = prev->i;
	prev->i = tmp->i;
	tmp->i = swap;
	return (build_steps(ps, ab == 'a' ? SA : SB));
}

int		ps_push(t_ps *ps, char ab)
{
	t_lst	*tmp;
	t_lst	*prev;

	if (!(tmp = (ab == 'b' ? ps->a : ps->b)))
		return (0);
	if (tmp->next)
	{
		while (tmp->next)
		{
			prev = tmp;
			tmp = tmp->next;
		}
		prev->next = NULL;
	}
	else if (ab == 'b')
		ps->a = NULL;
	else
		ps->b = NULL;
	lst_pushback((ab == 'b' ? &ps->b : &ps->a), tmp);
	(ab == 'b' ? --ps->len : ++ps->len);
	return (build_steps(ps, ab == 'a' ? PA : PB));
}

int		ps_rotate(t_ps *ps, char ab)
{
	t_lst	*tmp;
	t_lst	*prev;

	tmp = (ab == 'a' ? ps->a : ps->b);
	if (!tmp || !tmp->next)
		return (0);
	while (tmp->next)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = NULL;
	lst_pushfront((ab == 'a' ? &ps->a : &ps->b), tmp);
	return (build_steps(ps, ab == 'a' ? RA : RB));
}

int		ps_rrotate(t_ps *ps, char ab)
{
	t_lst	*tmp;

	tmp = (ab == 'a' ? ps->a : ps->b);
	if (!tmp || !tmp->next)
		return (0);
	if (ab == 'a')
		ps->a = tmp->next;
	else
		ps->b = tmp->next;
	tmp->next = NULL;
	lst_pushback((ab == 'a' ? &ps->a : &ps->b), tmp);
	return (build_steps(ps, ab == 'a' ? RRA : RRB));
}

int		ps_dswap(t_ps *ps)
{
	if (!ps->a || !ps->b || !ps->a->next || !ps->b->next)
		return (0);
	ps_swap(ps, 'a');
	ps_swap(ps, 'b');
	return (build_steps(ps, SS));
}

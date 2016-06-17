/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 13:18:06 by jgan              #+#    #+#             */
/*   Updated: 2016/02/16 13:18:09 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			ps_drotate(t_ps *ps)
{
	if (!ps->a || !ps->b || !ps->a->next || !ps->b->next)
		return (0);
	ps_rotate(ps, 'a');
	ps_rotate(ps, 'b');
	return (build_steps(ps, RR));
}

int			ps_drrotate(t_ps *ps)
{
	if (!ps->a || !ps->b || !ps->a->next || !ps->b->next)
		return (0);
	ps_rrotate(ps, 'a');
	ps_rrotate(ps, 'b');
	return (build_steps(ps, RRR));
}

int			build_steps(t_ps *ps, int op_id)
{
	t_lst	*A2;

	A2 = lst_last(ps->ops, 0);
	if ((op_id == SA && A2->i == SA) || (op_id == SB && A2->i == SB)
		|| (op_id == PA && A2->i == PB) || (op_id == PB && A2->i == PA)
		|| (op_id == RA && A2->i == RRA) || (op_id == RRA && A2->i == RA)
		|| (op_id == RB && A2->i == RRB) || (op_id == RRB && A2->i == RB)
		|| (op_id == RRR && A2->i == RR) || (op_id == RR && A2->i == RRR)
		|| (op_id == SS && A2->i == SS))
		A2->i = 0;
	else if ((op_id == SA && A2->i == SB) || (op_id == SB && A2->i == SA))
		A2->i = SS;
	else if ((op_id == RA && A2->i == RB) || (op_id == RB && A2->i == RA))
		A2->i = RR;
	else if ((op_id == RRA && A2->i == RRB) || (op_id == RRB && A2->i == RRA))
		A2->i = RRR;
	else if (A2->i == 0)
		A2->i = op_id;
	else if (A2->next)
		A2->next->i = op_id;
	else
		A2->next = lst_new(op_id);
	return (op_id);
}

static void	optimize_ops(t_ps *ps)
{
	t_lst	*A2;
	t_lst	*tmp;
	t_lst	*save;

	A2 = ps->ops;
	while (A1)
	{
		if (((A2->i == RRA || A2->i == RRB) && A1->i == RRR)
			|| ((A2->i == RA || A2->i == RB) && A1->i == RR))
		{
			tmp = A1;
			while ((tmp->i == RR || tmp->i == RRR) && (save = tmp))
				tmp = tmp->next;
			if ((tmp->i == (A2->i == RRA ? RRB : RRA))
				|| (tmp->i == (A2->i == RA ? RB : RA)))
			{
				A2->i = A2->i < 9 ? RR : RRR;
				save->next = tmp->next;
				free(tmp);
				A2 = ps->ops;
			}
		}
		A2 = A1;
	}
}

int			disp_ops(t_ps *ps)
{
	t_lst	*tmp;
	char	*s;
	int		pos;
	int		i;

	optimize_ops(ps);
	tmp = ps->ops;
	i = 0;
	while (tmp && ++i < ps->disp)
		tmp = tmp->next;
	while (tmp && (tmp->i && ++ps->disp) && !(i = 0))
	{
		if (ps->x && tmp->next && (pos = tmp->i))
			while (tmp->next && tmp->next->i == pos && ++i)
			{
				tmp = tmp->next;
				++ps->disp;
			}
		if (ps->x && i)
			ft_printf("%d", i + 1);
		if ((s = idtostr(ps, tmp->i)))
			ft_printf(!tmp->next || !tmp->next->i ? "%s\n" : "%s ", s);
		tmp = tmp->next;
	}
	return (1);
}

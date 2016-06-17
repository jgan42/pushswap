/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_optiop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:52:48 by jgan              #+#    #+#             */
/*   Updated: 2016/02/23 07:52:53 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			is_sort(t_lst *tmp, char ab)
{
	if (!tmp)
		return (1);
	while (tmp->next)
	{
		if ((ab == 'a' ? tmp->i < tmp->next->i : tmp->i > tmp->next->i))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

/*
**	p <=> previous operation
**	c <=> current operation
*/

static int	sub2_ps_optiop(t_ps *ps, int op_num, int op_max, int p)
{
	int		c;

	if (p != PA && (c = ps_push(ps, 'b')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_push(ps, 'a');
	}
	if (p != RRA && p != RRR && (c = ps_rotate(ps, 'a')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_rrotate(ps, 'a');
	}
	if (p != RA && p != RR && (c = ps_rrotate(ps, 'a')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_rotate(ps, 'a');
	}
	return (0);
}

static int	sub_ps_optiop(t_ps *ps, int op_num, int op_max, int p)
{
	int		c;

	if (p != SB && p != SS && (c = ps_swap(ps, 'b')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_swap(ps, 'b');
	}
	if (p != SS && p != SA && p != SB && (c = ps_dswap(ps)))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_dswap(ps);
	}
	if (p != PB && (c = ps_push(ps, 'a')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_push(ps, 'b');
	}
	return (sub2_ps_optiop(ps, op_num, op_max, c));
}

int			ps_optiop(t_ps *ps, int op_num, int op_max, int p)
{
	int		c;

	c = 0;
	if (op_num > op_max)
		return (0);
	if (op_num == op_max && !ps->b && is_sort(ps->a, 'a'))
		return (1);
	if (p != SA && p != SS && (c = ps_swap(ps, 'a')))
	{
		if (ps_optiop(ps, 1 + op_num, op_max, c))
			return (1);
		ps_swap(ps, 'a');
	}
	return (sub_ps_optiop(ps, op_num, op_max, c));
}

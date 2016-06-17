/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_select.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 07:52:23 by jgan              #+#    #+#             */
/*   Updated: 2016/02/23 07:52:25 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void ps_select_endphase(t_ps *ps, t_lst *B2)
{
	while (Ba->i != ps->min[0])
	{
		if (((B2 = lst_last(ps->b, -1)) && B1->i != ps->min[0] && B2->i > B1->i))
			ps_swap(ps, 'b');
		ps_rotate(ps, 'b');
	}
	while (!is_sort(Ba, 'b') || !is_sort(Aa, 'a'))
	{
		while (!is_sort(Aa, 'a'))
		{
			if ((B2 = lst_last(ps->a, -1)) && B2->i < B1->i)
				ps_swap(ps, 'a');
			ps_push(ps, 'b');
			if ((B2 = lst_last(ps->b, -1)) && B2->i > B1->i)
				ps_swap(ps, 'b');
		}
		while (!is_sort(Ba, 'b'))
		{
			if ((B2 = lst_last(ps->b, -1)) && B2->i > B1->i)
				ps_swap(ps, 'b');
			ps_push(ps, 'a');
			if ((B2 = lst_last(ps->a, -1)) && B2->i < B1->i)
				ps_swap(ps, 'a');
		}
	}
}

static int	few_count_rotate(t_ps *ps, t_lst *B2)
{
	if (!(is_extrema(ps, Ba->i) > 0 && B0->i > Ba->i))
		return (0);
	if (!(is_extrema(ps, Bb->i) > 0 && B0->i > Bb->i))
		return (1);
	if (!(Bc && is_extrema(ps, Bc->i) > 0 && B0->i > Bc->i))
		return (2);
	if (!(Bd && is_extrema(ps, Bd->i) > 0 && B0->i > Bd->i))
		return (3);
	if (!(Be && is_extrema(ps, Be->i) > 0 && B0->i > Be->i))
		return (4);
	if (!(Bf && is_extrema(ps, Bf->i) > 0 && B0->i > Bf->i))
		return (5);
	return (6);
}

static void	few_order_max(t_ps *ps, int rot)
{
	int		i;

	i = -1;
	ps_push(ps, 'a');
	while (++i < rot)
		ps_rrotate(ps, 'b');
	ps_push(ps, 'b');
	i = -1;
	while (++i < rot)
		ps_rotate(ps, 'b');
	ps_rotate(ps, 'b');
}

static void	ps_select_few_order(t_ps *ps, t_lst *B2)
{
	if (is_extrema(ps, B0->i) > 0)
		few_order_max(ps, few_count_rotate(ps, B2));
	else
	{
		if (is_extrema(ps, B2->i) < 0 && is_extrema(ps, B1->i) < 0
			&& B0->i < B2->i && B0->i < B1->i)
		{
			ps_push(ps, 'a');
			ps_rotate(ps, 'b');
			ps_push(ps, 'b');
			ps_swap(ps, 'b');
			ps_rrotate(ps, 'b');
		}
		else if (is_extrema(ps, B1->i) < 0 && B0->i < B1->i)
			ps_swap(ps, 'b');
	}
}

void		ps_select(t_ps *ps)
{
	t_lst	*B2;
	int		i;
	int		j;

	if (ps->v && Ba && disp_ops(ps))
		put_state(ps);
	if (!find_extrema_index(ps, &i, &j))
		find_extrema(ps, &i, &j);
//	ft_printf("i:%d|j:%d|m:%d|m:%d|m:%d|m:%d|M:%d|M:%d|M:%d|M:%d\n", i, j, ps->min[1],ps->min[2],ps->min[3],ps->min[4],ps->max[1],ps->max[2],ps->max[3],ps->max[4]);
	if (ps->len - j < i)
		while (++j <= ps->len)
			ps_rotate(ps, 'a');
	else
		while (--i > -1)
			ps_rrotate(ps, 'a');
	ps_push(ps, 'b');
	if (Ba && Bb && Ba->i == ps->min[0] && Bb->i == ps->max[0])
		ps_swap(ps, 'b');
	if (!(B2 = lst_last(ps->b, -2)))
		return (ps_select(ps));
	ps_select_few_order(ps, B2);
	if (Aa)
		return (ps_select(ps));
	ps_select_endphase(ps, B2);
	while (Ba)
			ps_push(ps, 'a');
}

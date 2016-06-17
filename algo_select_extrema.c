/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_select_extrema.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 00:07:57 by jgan              #+#    #+#             */
/*   Updated: 2016/02/28 00:07:59 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_extrema(t_ps *ps, int nb)
{
	int		i;

	i = 0;
	while (++i < 34)
		if (nb == ps->max[i] || (i < 31 && nb == ps->min[i]))
			return (nb == ps->max[i] ? 1 : -1);
	return (0);
}

int		find_extrema_index(t_ps *ps, int *i, int *j)
{
	t_lst	*tmp;
	int 	k;
	int		l;

	tmp = ps->a;
	k = 1;
	*i = 0;
	*j = 0;
	while (tmp)
	{
		l = 0;
		while (++l < 34)
		{
			if ((l < 31 && tmp->i == ps->min[l]) || tmp->i == ps->max[l])
			{
				*i = !*i ? k : *i;
				*j = k;
			}
		}
		tmp = tmp->next;
		++k;
	}
	return (*i ? 1 : 0);
}

void	find_extrema(t_ps *ps, int *i, int *j)
{
	t_lst	*t;
	int		k;

	k = 0;
	while (++k < 34)
	{
		if (k < 31)
			ps->min[k] = INT_MAX;
		ps->max[k] = INT_MIN;
	}
	t = ps->a;
	while (t)
	{
		ps->len > 700 ? find_extrema_min1(ps, t->i) : (int)k;
		ps->len > 200 ? find_extrema_min2(ps, t->i) : (int)k;
		find_extrema_min3(ps, t->i);
		ps->len > 700 ? find_extrema_max1(ps, t->i) : (int)k;
		ps->len > 200 ? find_extrema_max2(ps, t->i) : (int)k;
		find_extrema_max3(ps, t->i);
		t = t->next;
	}
	find_extrema_index(ps, i, j);
}

void	find_extrema_min1(t_ps *ps, int i)
{
	if (i < ps->min[29] || (i < ps->min[30] && i > ps->min[29]))
		ps->min[30] = i < ps->min[29] ? ps->min[29] : i;
	if (i < ps->min[28] || (i < ps->min[29] && i > ps->min[28]))
		ps->min[29] = i < ps->min[28] ? ps->min[28] : i;
	if (i < ps->min[27] || (i < ps->min[28] && i > ps->min[27]))
		ps->min[28] = i < ps->min[27] ? ps->min[27] : i;
	if (i < ps->min[26] || (i < ps->min[27] && i > ps->min[26]))
		ps->min[27] = i < ps->min[26] ? ps->min[26] : i;
	if (i < ps->min[25] || (i < ps->min[26] && i > ps->min[25]))
		ps->min[26] = i < ps->min[25] ? ps->min[25] : i;
	if (i < ps->min[24] || (i < ps->min[25] && i > ps->min[24]))
		ps->min[25] = i < ps->min[24] ? ps->min[24] : i;
	if (i < ps->min[23] || (i < ps->min[24] && i > ps->min[23]))
		ps->min[24] = i < ps->min[23] ? ps->min[23] : i;
	if (i < ps->min[22] || (i < ps->min[23] && i > ps->min[22]))
		ps->min[23] = i < ps->min[22] ? ps->min[22] : i;
	if (i < ps->min[21] || (i < ps->min[22] && i > ps->min[21]))
		ps->min[22] = i < ps->min[21] ? ps->min[21] : i;
	if (i < ps->min[20] || (i < ps->min[21] && i > ps->min[20]))
		ps->min[21] = i < ps->min[20] ? ps->min[20] : i;
	if (i < ps->min[19] || (i < ps->min[20] && i > ps->min[19]))
		ps->min[20] = i < ps->min[19] ? ps->min[19] : i;
	if (i < ps->min[18] || (i < ps->min[19] && i > ps->min[18]))
		ps->min[19] = i < ps->min[18] ? ps->min[18] : i;
}

void	find_extrema_min2(t_ps *ps, int i)
{
	if (i < ps->min[17] || (i < ps->min[18] && i > ps->min[17]))
		ps->min[18] = i < ps->min[17] ? ps->min[17] : i;
	if (i < ps->min[16] || (i < ps->min[17] && i > ps->min[16]))
		ps->min[17] = i < ps->min[16] ? ps->min[16] : i;
	if (i < ps->min[15] || (i < ps->min[16] && i > ps->min[15]))
		ps->min[16] = i < ps->min[15] ? ps->min[15] : i;
	if (i < ps->min[14] || (i < ps->min[15] && i > ps->min[14]))
		ps->min[15] = i < ps->min[14] ? ps->min[14] : i;
	if (i < ps->min[13] || (i < ps->min[14] && i > ps->min[13]))
		ps->min[14] = i < ps->min[13] ? ps->min[13] : i;
	if (i < ps->min[12] || (i < ps->min[13] && i > ps->min[12]))
		ps->min[13] = i < ps->min[12] ? ps->min[12] : i;
	if (i < ps->min[11] || (i < ps->min[12] && i > ps->min[11]))
		ps->min[12] = i < ps->min[11] ? ps->min[11] : i;
	if (i < ps->min[10] || (i < ps->min[11] && i > ps->min[10]))
		ps->min[11] = i < ps->min[10] ? ps->min[10] : i;
	if (i < ps->min[9] || (i < ps->min[10] && i > ps->min[9]))
		ps->min[10] = i < ps->min[9] ? ps->min[9] : i;
	if (i < ps->min[8] || (i < ps->min[9] && i > ps->min[8]))
		ps->min[9] = i < ps->min[8] ? ps->min[8] : i;
	if (i < ps->min[7] || (i < ps->min[8] && i > ps->min[7]))
		ps->min[8] = i < ps->min[7] ? ps->min[7] : i;
	if (i < ps->min[6] || (i < ps->min[7] && i > ps->min[6]))
		ps->min[7] = i < ps->min[6] ? ps->min[6] : i;
}

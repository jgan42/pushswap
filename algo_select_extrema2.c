/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_select_extrema2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/28 00:16:43 by jgan              #+#    #+#             */
/*   Updated: 2016/02/28 00:16:46 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_extrema_min3(t_ps *ps, int i)
{
	if (i < ps->min[5] || (i < ps->min[6] && i > ps->min[5]))
		ps->min[6] = i < ps->min[5] ? ps->min[5] : i;
	if (i < ps->min[4] || (i < ps->min[5] && i > ps->min[4]))
		ps->min[5] = i < ps->min[4] ? ps->min[4] : i;
	if (i < ps->min[3] || (i < ps->min[4] && i > ps->min[3]))
		ps->min[4] = i < ps->min[3] ? ps->min[3] : i;
	if (i < ps->min[2] || (i < ps->min[3] && i > ps->min[2]))
		ps->min[3] = i < ps->min[2] ? ps->min[2] : i;
	if (i < ps->min[1] || (i < ps->min[2] && i > ps->min[1]))
		ps->min[2] = i < ps->min[1] ? ps->min[1] : i;
	ps->min[1] = i < ps->min[1] ? i : ps->min[1];
}

void	find_extrema_max1(t_ps *ps, int i)
{
	if (i > ps->max[32] || (i > ps->max[33] && i < ps->max[32]))
		ps->max[33] = i > ps->max[32] ? ps->max[32] : i;
	if (i > ps->max[31] || (i > ps->max[32] && i < ps->max[31]))
		ps->max[32] = i > ps->max[31] ? ps->max[31] : i;
	if (i > ps->max[30] || (i > ps->max[31] && i < ps->max[30]))
		ps->max[31] = i > ps->max[30] ? ps->max[30] : i;
	if (i > ps->max[19] || (i > ps->max[30] && i < ps->max[19]))
		ps->max[30] = i > ps->max[19] ? ps->max[19] : i;
	if (i > ps->max[28] || (i > ps->max[29] && i < ps->max[28]))
		ps->max[29] = i > ps->max[28] ? ps->max[28] : i;
	if (i > ps->max[27] || (i > ps->max[28] && i < ps->max[27]))
		ps->max[28] = i > ps->max[27] ? ps->max[27] : i;
	if (i > ps->max[26] || (i > ps->max[27] && i < ps->max[26]))
		ps->max[27] = i > ps->max[26] ? ps->max[26] : i;
	if (i > ps->max[25] || (i > ps->max[26] && i < ps->max[25]))
		ps->max[26] = i > ps->max[25] ? ps->max[25] : i;
	if (i > ps->max[24] || (i > ps->max[25] && i < ps->max[24]))
		ps->max[25] = i > ps->max[24] ? ps->max[24] : i;
	if (i > ps->max[23] || (i > ps->max[24] && i < ps->max[23]))
		ps->max[24] = i > ps->max[23] ? ps->max[23] : i;
	if (i > ps->max[22] || (i > ps->max[23] && i < ps->max[22]))
		ps->max[23] = i > ps->max[22] ? ps->max[22] : i;
	if (i > ps->max[21] || (i > ps->max[22] && i < ps->max[21]))
		ps->max[22] = i > ps->max[21] ? ps->max[21] : i;
}

void	find_extrema_max2(t_ps *ps, int i)
{
	if (i > ps->max[20] || (i > ps->max[21] && i < ps->max[20]))
		ps->max[21] = i > ps->max[20] ? ps->max[20] : i;
	if (i > ps->max[19] || (i > ps->max[20] && i < ps->max[19]))
		ps->max[20] = i > ps->max[19] ? ps->max[19] : i;
	if (i > ps->max[18] || (i > ps->max[19] && i < ps->max[18]))
		ps->max[19] = i > ps->max[18] ? ps->max[18] : i;
	if (i > ps->max[17] || (i > ps->max[18] && i < ps->max[17]))
		ps->max[18] = i > ps->max[17] ? ps->max[17] : i;
	if (i > ps->max[16] || (i > ps->max[17] && i < ps->max[16]))
		ps->max[17] = i > ps->max[16] ? ps->max[16] : i;
	if (i > ps->max[15] || (i > ps->max[16] && i < ps->max[15]))
		ps->max[16] = i > ps->max[15] ? ps->max[15] : i;
	if (i > ps->max[14] || (i > ps->max[15] && i < ps->max[14]))
		ps->max[15] = i > ps->max[14] ? ps->max[14] : i;
	if (i > ps->max[13] || (i > ps->max[14] && i < ps->max[13]))
		ps->max[14] = i > ps->max[13] ? ps->max[13] : i;
	if (i > ps->max[12] || (i > ps->max[13] && i < ps->max[12]))
		ps->max[13] = i > ps->max[12] ? ps->max[12] : i;
	if (i > ps->max[11] || (i > ps->max[12] && i < ps->max[11]))
		ps->max[12] = i > ps->max[11] ? ps->max[11] : i;
	if (i > ps->max[10] || (i > ps->max[11] && i < ps->max[10]))
		ps->max[11] = i > ps->max[10] ? ps->max[10] : i;
	if (i > ps->max[9] || (i > ps->max[10] && i < ps->max[9]))
		ps->max[10] = i > ps->max[9] ? ps->max[9] : i;
}

void	find_extrema_max3(t_ps *ps, int i)
{
	if (i > ps->max[8] || (i > ps->max[9] && i < ps->max[8]))
		ps->max[9] = i > ps->max[8] ? ps->max[8] : i;
	if (i > ps->max[7] || (i > ps->max[8] && i < ps->max[7]))
		ps->max[8] = i > ps->max[7] ? ps->max[7] : i;
	if (i > ps->max[6] || (i > ps->max[7] && i < ps->max[6]))
		ps->max[7] = i > ps->max[6] ? ps->max[6] : i;
	if (i > ps->max[5] || (i > ps->max[6] && i < ps->max[5]))
		ps->max[6] = i > ps->max[5] ? ps->max[5] : i;
	if (i > ps->max[4] || (i > ps->max[5] && i < ps->max[4]))
		ps->max[5] = i > ps->max[4] ? ps->max[4] : i;
	if (i > ps->max[3] || (i > ps->max[4] && i < ps->max[3]))
		ps->max[4] = i > ps->max[3] ? ps->max[3] : i;
	if (i > ps->max[2] || (i > ps->max[3] && i < ps->max[2]))
		ps->max[3] = i > ps->max[2] ? ps->max[2] : i;
	if (i > ps->max[1] || (i > ps->max[2] && i < ps->max[1]))
		ps->max[2] = i > ps->max[1] ? ps->max[1] : i;
	ps->max[1] = i > ps->max[1] ? i : ps->max[1];
}

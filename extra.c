/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:04:00 by jgan              #+#    #+#             */
/*   Updated: 2016/02/13 15:04:01 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			lst_size(t_lst *start)
{
	int i;

	i = 0;
	while (start)
	{
		start = start->next;
		++i;
	}
	return (i);
}

char		*idtostr(t_ps *ps, int op_id)
{
	if (op_id == SA)
		return (ps->c ? "\e[31msa\e[0m" : "sa");
	if (op_id == SB)
		return (ps->c ? "\e[31msb\e[0m" : "sb");
	if (op_id == SS)
		return (ps->c ? "\e[31mss\e[0m" : "ss");
	if (op_id == PA)
		return (ps->c ? "\e[32mpa\e[0m" : "pa");
	if (op_id == PB)
		return (ps->c ? "\e[32mpb\e[0m" : "pb");
	if (op_id == RA)
		return (ps->c ? "\e[34mra\e[0m" : "ra");
	if (op_id == RB)
		return (ps->c ? "\e[34mrb\e[0m" : "rb");
	if (op_id == RR)
		return (ps->c ? "\e[34mrr\e[0m" : "rr");
	if (op_id == RRA)
		return (ps->c ? "\e[36mrra\e[0m" : "rra");
	if (op_id == RRB)
		return (ps->c ? "\e[36mrrb\e[0m" : "rrb");
	if (op_id == RRR)
		return (ps->c ? "\e[36mrrr\e[0m" : "rrr");
	return (NULL);
}

void		put_state(t_ps *ps)
{
	t_lst	*A2;

	A2 = ps->a;
	ft_printf("a: ");
	while (A2)
	{
		ft_printf(COMPRESS_A ? "%d.." : "%d ", A2->i);
		if (ps->s)
			while (A1 && A0 && A2->i > A1->i && A1->i > A0->i)
				A2 = A1;
		A2 = A1;
	}
	if ((A2 = ps->b))
	{
		ft_printf("\nb: ");
		while (A2)
		{
			ft_printf(COMPRESS_B ? "%d.." : "%d ", A2->i);
			if (ps->s)
				while (A1 && A0 && A2->i < A1->i && A1->i < A0->i)
					A2 = A1;
			A2 = A1;
		}
	}
	ft_putchar('\n');
}

static int	is_double(t_ps *ps, int tmp)
{
	t_lst *a;

	if (tmp < ps->min[0])
		ps->min[0] = tmp;
	if (tmp > ps->max[0])
		ps->max[0] = tmp;
	a = ps->a;
	while (a)
	{
		if (a->i == tmp)
			return (0);
		a = a->next;
	}
	++ps->len;
	return (1);
}

int			build_lst(t_ps *ps, char **av)
{
	long	tmp;
	int		i;
	int		j;

	i = 1;
	while (av[i] && av[i][0] == '-' && av[i][1] == '-')
		++i;
	if (!av[i])
		return (0);
	while (av[i + ps->len])
	{
		j = av[i + ps->len][0] && av[i + ps->len][0] == '-' ? 0 : -1;
		if (!av[i + ps->len][j + 1])
			return (0);
		while (av[i + ps->len][++j])
			if (!ft_isdigit(av[i + ps->len][j]))
				return (0);
		if (ft_strlen(av[i + ps->len]) > 11
			|| (tmp = ft_atoli(av[i + ps->len])) > INT_MAX
			|| tmp < INT_MIN || !is_double(ps, (int)tmp)
			|| !lst_pushfront(&ps->a, lst_new((int)tmp)))
			return (0);
	}
	return (1);
}

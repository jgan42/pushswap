/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:25:18 by jgan              #+#    #+#             */
/*   Updated: 2016/02/08 13:25:19 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_ps(t_ps *ps)
{
	ps->a = NULL;
	ps->b = NULL;
	ps->ops = lst_new(0);
	ps->c = 0;
	ps->f = 0;
	ps->n = 0;
	ps->v = 0;
	ps->s = 0;
	ps->t = 0;
	ps->x = 0;
	ps->len = 0;
	ps->disp = 1;
	ps->ret = 0;
	ps->min[0] = INT_MAX;
	ps->max[0] = INT_MIN;
	ps->ct = clock();
}

static char	get_flags(t_ps *ps, char **av)
{
	int		i;
	int		j;

	i = 0;
	while (av[++i] && av[i][0] == '-' && av[i][1] == '-')
	{
		j = 1;
		if (!av[i][2])
			return ('0');
		while (av[i][++j])
		{
			ps->n = av[i][j] == 'n' ? 1 : ps->n;
			ps->v = av[i][j] == 'v' ? 1 : ps->v;
			ps->c = av[i][j] == 'c' ? 1 : ps->c;
			ps->f = av[i][j] == 'f' ? 1 : ps->f;
			ps->t = av[i][j] == 't' ? 1 : ps->t;
			ps->s = av[i][j] == 's' ? 1 : ps->s;
			ps->x = av[i][j] == 'x' ? 1 : ps->x;
			if (av[i][j] != 'n' && av[i][j] != 'v' && av[i][j] != 'c'
				&& av[i][j] != 'f' && av[i][j] != 't' && av[i][j] != 's'
				&& av[i][j] != 'x')
				return (av[i][j]);
		}
	}
	return (0);
}

static void	print_rules(void)
{
	ft_putstr("usage: ./push_swap [--cfnstvx] [int ...]\n");
	ft_putstr("--c Coloring operations\n");
	ft_putstr("--v Display piles status before few operations\n");
	ft_putstr("--f Display piles status at the end\n");
	ft_putstr("--s \"Compress\" status by ordered");
	ft_putstr(" \"segment\" (e.g.: 1 2 3 5 12 9 8 4 0 7 => 1..5 12..0 7)\n");
	ft_putstr("--x Group repeated operations (e.g.: rb ra ra ra => rb 3ra)\n");
	ft_putstr("--n Number of operations\n--t Time of execution\n");
}

static void	push_swap(t_ps *ps)
{
	int		i;

	i = 0;
	while (++i < 34)
	{
		if (i < 31)
			ps->min[i] = ps->min[0];
		ps->max[i] = ps->max[0];
	}
	i = 0;
	if (ps->v)
		put_state(ps);
	while (!ps->ret && i < (ps->len > 15 ? 8 : 12))
	{
		ps->ret = ps_optiop(ps, 0, i, 0);
		++i;
	}
	if (!ps->ret)
		ps_select(ps);
	disp_ops(ps);
}

int			main(int ac, char **av)
{
	t_ps	ps;
	char	f;

	init_ps(&ps);
	if ((f = get_flags(&ps, av)) || ac == 1 || !build_lst(&ps, av))
	{
		if (f)
			ft_printf("push_swap illegal option -- %c\n", f);
		print_rules();
		if (ac != 1)
			write(2, "Error\n", 6);
		return (0);
	}
	push_swap(&ps);
	if (ps.f)
		put_state(&ps);
	if (ps.n)
		ft_printf("Total of %d operations\n", lst_size(ps.ops));
	if (ps.t)
		ft_printf("Push_swapped in %.4fs\n", (float)(clock() - ps.ct) / CPS);
	return (0);
}

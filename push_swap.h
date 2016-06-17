/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 13:25:37 by jgan              #+#    #+#             */
/*   Updated: 2016/02/08 13:25:39 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <time.h>

# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

# define Aa ps->a
# define Ab ps->a->next
# define A2 la
# define A1 la->next
# define A0 la->next->next
# define Ba ps->b
# define Bb Ba->next
# define Bc Bb->next
# define Bd Bc->next
# define Be Bd->next
# define Bf Be->next
# define B2 lb
# define B1 B2->next
# define B0 B1->next

# define CPS CLOCKS_PER_SEC
# define COMPRESS_A ps->s && A1 && A0 && la->i > A1->i && A1->i > A0->i
# define COMPRESS_B ps->s && A1 && A0 && la->i < A1->i && A1->i < A0->i

typedef struct	s_lst
{
	int				i;
	struct s_lst	*next;
}				t_lst;
typedef struct	s_pushswap
{
	t_lst	*a;
	t_lst	*b;
	t_lst	*ops;

	char	c;
	char	f;
	char	n;
	char	v;
	char	s;
	char	t;
	char	x;

	clock_t	ct;
	int		disp;
	int		ret;
	int		len;
	int		min[31];
	int		max[34];
}				t_ps;

t_lst			*lst_new(int i);
t_lst			*lst_last(t_lst *start, int null);
int				lst_clear(t_lst **start);
int				lst_pushfront(t_lst **start, t_lst *new);
int				lst_pushback(t_lst **start, t_lst *new);
int				lst_size(t_lst *start);

int				ps_push(t_ps *ps, char ab);
int				ps_swap(t_ps *ps, char ab);
int				ps_rotate(t_ps *ps, char ab);
int				ps_rrotate(t_ps *ps, char ab);
int				ps_dswap(t_ps *ps);
int				ps_drotate(t_ps *ps);
int				ps_drrotate(t_ps *ps);

int				disp_ops(t_ps *ps);
char			*idtostr(t_ps *ps, int op_num);
int				build_lst(t_ps *ps, char **av);
int				build_steps(t_ps *ps, int op_id);
void			put_state(t_ps *ps);

int				ps_optiop(t_ps *ps, int op_num, int op_max, int last_op);
int				is_sort(t_lst *tmp, char ab);

void			ps_select(t_ps *ps);
int				is_extrema(t_ps *ps, int nb);
int				find_extrema_index(t_ps *ps, int *i, int *j);
void			find_extrema(t_ps *ps, int *i, int *j);
void			find_extrema_min1(t_ps *ps, int i);
void			find_extrema_min2(t_ps *ps, int i);
void			find_extrema_min3(t_ps *ps, int i);
void			find_extrema_max1(t_ps *ps, int i);
void			find_extrema_max2(t_ps *ps, int i);
void			find_extrema_max3(t_ps *ps, int i);
#endif

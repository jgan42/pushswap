/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgan <jgan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/10 22:54:29 by jgan              #+#    #+#             */
/*   Updated: 2015/11/10 22:55:19 by jgan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int		i;

	if (!f || !s)
		return ;
	i = 0;
	while (s[i])
	{
		f(s + i);
		++i;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands01.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:03 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 19:19:54 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_hell *my_s, int argc) //поменять местами 0 и 1 индекс в стеке а
{
	int	tmp;
	int	i;

	i = 0;
	if (cnt_num(my_s->a, argc) < 2)
		return ;
	write(1, "sa\n", 3);
	tmp = my_s->a[0];
	my_s->a[0] = my_s->a[1];
	my_s->a[1] = tmp;
}

void	sb(t_hell *my_s, int argc) //поменять местами 0 и 1 индекс в стеке b
{
	int	tmp;

	if (cnt_num(my_s->b, argc) < 2)
		return ;
	write(1, "sb\n", 3);
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	ss(t_hell *my_s, int argc) //поменять местами 0 и 1 индекс в стеке a и b одновременно
{
	int	tmp;
	int	i;

	i = 0;
	if (cnt_num(my_s->a, argc) < 2)
		return ;
	write(1, "ss\n", 3);
	tmp = my_s->a[0];
	my_s->a[0] = my_s->a[1];
	my_s->a[1] = tmp;
	if (cnt_num(my_s->b, argc) < 2)
		return ;
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	pa(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->b, argc) < 1)
		return ;
	write(1, "pa\n", 3);
	tmp = my_s->b[0];
	i = cnt_num(my_s->a, argc);
	while (i >= 0)
	{
		my_s->a[i + 1] = my_s->a[i];
		i--;
	}
	my_s->a[0] = tmp;
	while (++i < cnt_num(my_s->b, argc))
		my_s->b[i] = my_s->b[i + 1];
	my_s->b[i] = 0;
}

void	pb(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	if (cnt_num(my_s->a, argc) < 1)
		return ;
	write(1, "pb\n", 3);
	tmp = my_s->a[0];
	i = cnt_num(my_s->b, argc);
	if (i == 0)
		my_s->b[0] = tmp;
	else
	{
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
	i = -1;
	while (++i < cnt_num(my_s->a, argc) - 1)
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i] = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands03.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:33 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/02 18:29:19 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_hell *my_s, int argc) //поднимаем снизу наверх
{
	int	tmp;
	int	i;

	write(1, "rra\n", 4);
	if (cnt_num(my_s->a, argc) > 1)
	{
		i = cnt_num(my_s->a, argc) - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
}

void	rrb(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	write(1, "rrb\n", 4);
	if (cnt_num(my_s->b, argc) > 1)
	{
		i = cnt_num(my_s->b, argc) - 1;
		tmp = my_s->b[i];
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
}

void	rrr(t_hell *my_s, int argc)
{
	int	tmp;
	int	i;

	write(1, "rrr\n", 4);
	if (cnt_num(my_s->a, argc) > 1)
	{
		i = cnt_num(my_s->a, argc) - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
	if (cnt_num(my_s->b, argc) > 1)
	{
		i = cnt_num(my_s->b, argc) - 1;
		tmp = my_s->b[i++];
		while (--i > 0)
			my_s->b[i] = my_s->b[i - 1];
		my_s->b[0] = tmp;
	}
}

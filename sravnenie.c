/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sravnenie.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:38:11 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 12:38:13 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sravnenie(int *four, int j, t_hell *my_s)
{
	int	min;
	int	t;
	int	index;

	index = 0;
	min = four[0];
	t = 1;
	while (t < 4)
	{
		if (min > four[t])
		{
			index = t;
			min = four[t];
		}
		t++;
	}
	my_s->min_dist[j] = min;
	my_s->steps[j] = index;
}

void	if_zero(t_hell *my_s, int min_index, int argc)
{
	int	counter;

	counter = -1;
	if (my_s->pos_in_a[min_index] > min_index)
	{
		while (++counter < min_index)
			rr(my_s, argc);
		counter = my_s->pos_in_a[min_index] - min_index;
		while (counter--)
			ra(my_s, argc);
	}
	else
	{
		while (++counter < my_s->pos_in_a[min_index])
			rr(my_s, argc);
		counter = min_index - my_s->pos_in_a[min_index];
		while (counter--)
			rb(my_s, argc);
	}
}

void	if_one(t_hell *my_s, int min_index, int argc)
{
	int	counter;

	counter = -1;
	if (cnt_num(my_s->a, argc) - my_s->pos_in_a[min_index]
		> cnt_num(my_s->b, argc) - min_index)
	{
		counter = cnt_num(my_s->b, argc) - min_index;
		while (counter--)
			rrr(my_s, argc);
		counter = cnt_num(my_s->a, argc) - my_s->pos_in_a[min_index]
			- cnt_num(my_s->b, argc) + min_index;
		while (counter--)
			rra(my_s, argc);
	}
	else
	{
		while (++counter < cnt_num(my_s->a, argc) - my_s->pos_in_a[min_index])
			rrr(my_s, argc);
		counter = cnt_num(my_s->b, argc) - min_index
			- cnt_num(my_s->a, argc) + my_s->pos_in_a[min_index];
		while (counter--)
			rrb(my_s, argc);
	}
}

void	if_two(t_hell *my_s, int min_index, int argc)
{
	int	counter;

	counter = my_s->pos_in_a[min_index];
	while (counter--)
		ra(my_s, argc);
	counter = cnt_num(my_s->b, argc) - min_index;
	while (counter--)
		rrb(my_s, argc);
}

void	if_three(t_hell *my_s, int min_index, int argc)
{
	int	counter;

	counter = cnt_num(my_s->a, argc) - my_s->pos_in_a[min_index];
	while (counter--)
		rra(my_s, argc);
	counter = min_index;
	while (counter--)
		rb(my_s, argc);
}

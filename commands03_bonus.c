/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands03_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:25 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 12:37:27 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rra(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a > 1)
	{
		i = my_s->len_a - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
}

void	rrb(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_b > 1)
	{
		i = my_s->len_b - 1;
		tmp = my_s->b[i];
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
}

void	rrr(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a > 1)
	{
		i = my_s->len_a - 1;
		tmp = my_s->a[i];
		while (i > 0)
		{
			my_s->a[i] = my_s->a[i - 1];
			i--;
		}
		my_s->a[0] = tmp;
	}
	if (my_s->len_b > 1)
	{
		i = my_s->len_b - 1;
		tmp = my_s->b[i];
		while (i > 0)
		{
			my_s->b[i] = my_s->b[i - 1];
			i--;
		}
		my_s->b[0] = tmp;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands01_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:36:53 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 12:36:55 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	sa(t_check *my_s)
{
	int	tmp;

	if (my_s->len_a < 2)
		return ;
	tmp = my_s->a[0];
	my_s->a[0] = my_s->a[1];
	my_s->a[1] = tmp;
}

void	sb(t_check *my_s)
{
	int	tmp;

	if (my_s->len_b < 2)
		return ;
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	ss(t_check *my_s)
{
	int	tmp;

	if (my_s->len_a >= 2)
	{
		tmp = my_s->a[0];
		my_s->a[0] = my_s->a[1];
		my_s->a[1] = tmp;
	}
	if (my_s->len_b < 2)
		return ;
	tmp = my_s->b[0];
	my_s->b[0] = my_s->b[1];
	my_s->b[1] = tmp;
}

void	pa(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_b < 1)
		return ;
	tmp = my_s->b[0];
	i = my_s->len_a;
	while (i >= 0)
	{
		my_s->a[i + 1] = my_s->a[i];
		i--;
	}
	my_s->a[0] = tmp;
	my_s->len_a += 1;
	while (++i < my_s->len_b)
	{
		my_s->b[i] = my_s->b[i + 1];
	}
	my_s->b[i] = 0;
	my_s->len_b -= 1;
}

void	pb(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a < 1)
		return ;
	tmp = my_s->a[0];
	i = my_s->len_b;
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
	my_s->len_b += 1;
	i = -1;
	while (++i < my_s->len_a)
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i - 1] = 0;
	my_s->len_a -= 1;
}

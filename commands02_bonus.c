/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands02_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:10 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 12:37:11 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ra(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a < 2)
		return ;
	i = -1;
	tmp = my_s->a[0];
	while (++i + 1 < my_s->len_a)
		my_s->a[i] = my_s->a[i + 1];
	my_s->a[i] = tmp;
}

void	rb(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_b < 2)
		return ;
	i = -1;
	tmp = my_s->b[0];
	while (++i + 1 < my_s->len_b)
		my_s->b[i] = my_s->b[i + 1];
	my_s->b[i] = tmp;
}

void	rr(t_check *my_s)
{
	int	tmp;
	int	i;

	if (my_s->len_a > 1)
	{
	i = -1;
		tmp = my_s->a[0];
		while (++i + 1 < my_s->len_a)
			my_s->a[i] = my_s->a[i + 1];
		my_s->a[i] = tmp;
	}
	if (my_s->len_b > 1)
	{	
		i = -1;
		tmp = my_s->b[0];
		while (++i + 1 < my_s->len_b)
			my_s->b[i] = my_s->b[i + 1];
		my_s->b[i] = tmp;
	}
}

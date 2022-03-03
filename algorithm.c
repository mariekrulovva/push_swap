/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:36:25 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 18:35:50 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//подсчитываем сколько нужно команд для чисел в стеке b, чтобы оказаться на нужной позиции в стеке а

void	algorithm2(int j, int argc, t_hell *my_s)
{
	int	i;

	i = 0;
	while (my_s->a[i] && i < argc - 1)
	{
		if (my_s->b[j] > my_s->a[i])
		{
			while (my_s->a[i] && my_s->b[j] > my_s->a[i])
				i++;
			if (my_s->a[i] && my_s->b[j] < my_s->a[i])
			{
				algorithm2_2(my_s, i, j, argc);
				return ;
			}
			else
			{
				func(my_s, 0, j, argc);
				return ;
			}
		}
		i++;
	}
}

void	algorithm2_2(t_hell *my_s, int i, int j, int argc)
{
	if (i < cnt_num(my_s->a, argc) - i) //i-кол-во комманд для скидывания сверху вниз(ra), а (cnt_num-i) - кол-во комманд для поднятия снизу наверх(rra)
	{
		my_s->pos_in_a[j] = i; //в массив позиций в стеке а заносим индекс куда нужно положить наше число из стека b
		func(my_s, i, j, argc);
		return ;
	}
	else
	{
		my_s->pos_in_a[j] = i;
		func(my_s, i, j, argc);
		return ;
	}
}

//рассчитываем сколько команд нужно для каждого пути

void	func(t_hell *my_s, int i, int j, int argc)
{
	int	four[4]; //есть 4 пути,чтоб перекинуть число из стека b в стек а

	if (i > j) //для одновременных команд сверху вниз
	{
		my_s->pos_in_a[j] = i;
		four[0] = i;
	}
	else
		four[0] = j;
	if (cnt_num(my_s->a, argc) - i > cnt_num(my_s->b, argc) - j) //для одновременных команд снизу наверх
		four[1] = cnt_num(my_s->a, argc) - i;
	else
		four[1] = cnt_num(my_s->b, argc) - j;
	four[2] = i + cnt_num(my_s->b, argc) - j; //ra+rrb
	four[3] = j + cnt_num(my_s->a, argc) - i; //rb+rra
	sravnenie(four, j, my_s);
}

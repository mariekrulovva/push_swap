/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:46 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/20 14:33:24 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//сначала ищем мин значение в incoming,потом сортируем его

void	sorting_incoming(t_hell *my_s, int argc)
{
	int	q;
	int	p;
	int	min;

	check_errors(my_s, argc); //проверяем,чтоб было все корректно
	my_s->sorted[0] = -2147483648; //зачем?
	q = -1;
	min = 2147483647; //чтоб перезаписать на любое встретившееся число 
	while (++q < argc - 1)
		if (my_s->incoming[q] < min)
			min = my_s->incoming[q]; //здесь перезаписываем min
	my_s->sorted[0] = min; //затем min записываем в нулевой индекс, чтоб отсортироваит
	p = 0;
	while (++p < argc - 1) //потому что 0 индекс уже заполнен
	{
		q = -1; //заново начинаем, чтоб заполнить все остальные индексы
		min = 2147483647;
		while (++q < argc - 1)
			if (my_s->incoming[q] < min
				&& my_s->incoming[q] > my_s->sorted[p - 1]) //incoming[q] больше предыдущего найденного
				min = my_s->incoming[q];
		my_s->sorted[p] = min;
	}
}

//ищем повторения и проверяем входящий массив на то, отсортирован ли он

void	check_errors(t_hell *my_s, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i; //
		while (++j < argc - 1)
		{
			if (my_s->incoming[i] == my_s->incoming[j]) //проверяем по порядку значения (0 c 1, 0 c 2 и тд, потом 1 с 2, 1 с 3 и тд)
				for_free(my_s, 1);
		}
	}
	i = -1;
	while (++i < argc - 2) //в конце сравниваем предпоследний индекс с последним
	{
		if (my_s->incoming[i] > my_s->incoming[i + 1])
			return ;
	}
	for_free(my_s, -1); //если отсортирован, то фришим и завершаем программу
}

//заполняем стек a от 1 до argc-1

void	fill_cont_a(t_hell *my_s, int argc)
{
	int	p;
	int	q;

	p = 0;
	while (p < argc - 1)
	{
		q = 0;
		while (q < argc - 1)
		{
			if (my_s->sorted[p] == my_s->incoming[q]) //ищем sorted[p] в incoming[q]
				my_s->a[q] = p + 1; //в стек а на позицию q пишем 1
			q++;
		}
		p++;
	}
	if (argc < 7)
		sorting_min(my_s, argc);
}

//pushing except min and max to b

void	pushing_to_b(t_hell *my_s, int argc)
{
	int	i;
	int	cnt;

	i = -1;
	cnt = cnt_num(my_s->a, argc);
	while (++i < cnt)
	{
		if (my_s->a[0] == 1 || my_s->a[0] == argc - 1)
			ra(my_s, argc);
		else
			pb(my_s, argc);
		if (my_s->b[0] > argc / 2)
			rb(my_s, argc);
	}
}

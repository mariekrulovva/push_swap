/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:36:06 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/02 16:05:29 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	for_malloc(t_hell *my_s, int argc)
{
	my_s->a = malloc(sizeof(int) * (argc - 1)); //1 индекс не нужен, тк это название программы
	if (!my_s->a)
		for_free(my_s, 0);
	my_s->b = malloc(sizeof(int) * (argc - 1)); //выделяем память для стека б
	if (!my_s->b)
		for_free(my_s, 0); //если не получилось выделить, то освобождаем
	my_s->steps = malloc(sizeof(int) * (argc - 1));
	if (!my_s->steps)
		for_free(my_s, 0);
	my_s->pos_in_a = malloc(sizeof(int) * (argc - 1));
	if (!my_s->pos_in_a)
		for_free(my_s, 0);
	my_s->min_dist = malloc(sizeof(int) * (argc - 1));
	if (!my_s->min_dist)
		for_free(my_s, 0);
	my_s->incoming = malloc(sizeof(int) * (argc - 1));
	if (!my_s->incoming)
		for_free(my_s, 0);
	my_s->sorted = malloc(sizeof(int) * (argc - 1));
	if (!my_s->sorted)
		for_free(my_s, 0);
}

void	for_free(t_hell *my_s, int i)
{
	if (my_s->a) //случайно не освободим то, что не нужно
		free(my_s->a);
	if (my_s->b)
		free(my_s->b);
	if (my_s->steps)
		free(my_s->steps);
	if (my_s->pos_in_a)
		free(my_s->pos_in_a);
	if (my_s->min_dist)
		free(my_s->min_dist);
	if (my_s->incoming)
		free(my_s->incoming);
	if (my_s->sorted)
		free(my_s->sorted);
	if (i == 0)
		write(2, "Memory allocation error\n", 24);
	if (i > 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	for_bzero1(t_hell *my_s, int argc) //заполняем нулями
{
	ft_bzero(my_s->b, argc); //заполняем нулями стек б
	ft_bzero(my_s->pos_in_a, argc); //заполняем нулями массив позиций в а
	ft_bzero(my_s->min_dist, argc); //заполняем нулями массив минимальной дистанции
}

void	for_bzero2(t_hell *my_s, int argc)
{
	ft_bzero(my_s->pos_in_a, argc);
	ft_bzero(my_s->min_dist, argc);
}

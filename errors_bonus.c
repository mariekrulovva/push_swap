/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:37:40 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/21 15:25:29 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_errors(t_check *my_s, int argc)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc - 1)
		{
			if (my_s->a[i] == my_s->a[j]) //ищем дубликаты и выдаем ошибку, если нашли
				for_free(my_s, 1);
		}
	}
	i = -1;
	while (++i < argc - 2)
	{
		if (my_s->a[i] > my_s->a[i + 1]) //если срабатывает условие,значит,массив не отсортирован
			return ;
	}
	for_free(my_s, -1);
}

void	for_free(t_check *my_s, int i)
{
	if (my_s->a != NULL)
		free(my_s->a);
	if (my_s->b != NULL)
		free(my_s->b);
	if (i == 0)
		write(2, "Memory allocation error\n", 24);
	if (i > 0)
		write(2, "Error\n", 6);
	exit(0);
}

void	check_sort_mas_a(t_check *my_s, int argc)
{
	int	i;

	i = 0;
	if (my_s->b[0]) //те в стеке b что-то есть, и стек а не отсортирован до конца
	{
		write(1, "KO\n", 3);
		for_free(my_s, -1);
	}
	while (i < argc - 2)
	{
		if (my_s->a[i] > my_s->a[i + 1])
		{
			write(1, "KO\n", 3);
			for_free(my_s, -1);
		}
		i++;
	}
	write(1, "OK\n", 3);
	for_free(my_s, -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:38:04 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/02 18:29:52 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//сортируем массив, если в нем до 5 параметров

void	sorting_min(t_hell *my_s, int argc)
{
	if (argc == 3) //2 числа
		sa(my_s, argc); //поменять местами 1 со 2
	else if (argc == 4)
		sort_3(my_s, argc);
	else if (argc == 5)
		sort_4(my_s, argc);
	else if (argc == 6)
		sort_5(my_s, argc);
	for_free(my_s, -1);
}

//если у нас 3 числа во входящем массиве

void	sort_3(t_hell *my_s, int argc)
{
	if (my_s->a[0] < my_s->a[1] && my_s->a[1] > my_s->a[2]
		&& my_s->a[0] > my_s->a[2])
		rra(my_s, argc); //снизу закидываем наверх
	else if (my_s->a[0] < my_s->a[1]
		&& my_s->a[1] > my_s->a[2]
		&& my_s->a[0] < my_s->a[2])
	{
		sa(my_s, argc);
		ra(my_s, argc);
	}
	else if (my_s->a[0] > my_s->a[1] && my_s->a[1] > my_s->a[2])
	{
		sa(my_s, argc);
		rra(my_s, argc);
	}
	else if (my_s->a[0] > my_s->a[1]
		&& my_s->a[1] < my_s->a[2]
		&& my_s->a[0] < my_s->a[2])
		sa(my_s, argc);
	else if (my_s->a[0] > my_s->a[1]
		&& my_s->a[1] < my_s->a[2]
		&& my_s->a[0] > my_s->a[2])
		ra(my_s, argc);
}

//if in stack only 4 number

void	sort_4(t_hell *my_s, int argc)
{
	int	i;

	i = 0;
	while (my_s->a) //мы уже записали 1
	{
		if (my_s->a[i] == 1) //i будет таким, где находится записанная единица
			break ;
		i++;
	}
	if (i <= 2) //если у нас единица на индексах 0,1 или 2
		while (i-- != 0)
			ra(my_s, argc); //перекидываем сверху все числа в конец, пока 1 не станет в начало
	else
		rra(my_s, argc);
	pb(my_s, argc); //перекидываем 1 в стек b
	sort_3(my_s, argc); //сортируем 3 оставшихся числа
	pa(my_s, argc); //перекидываем 1 обратно из стека b в стек а
}

//if in stack only 5 number

void	sort_5(t_hell *my_s, int argc)
{
	int	i;

	i = -1;
	while (++i < cnt_num(my_s->a, argc)) //пока i < количества чисел в стеке а
	{
		if (my_s->a[0] == 1 || my_s->a[0] == 2)
			pb(my_s, argc);
		else
			ra(my_s, argc); //скидываем вниз
	}
	sort_3(my_s, 4);
	if (my_s->b[0] == 1) //нужно, чтоб в b[0] лежала 2,чтобы ее перекинуть в первую очередь
		sb(my_s, argc);
	pa(my_s, argc);
	pa(my_s, argc);
}

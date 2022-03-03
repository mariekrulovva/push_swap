/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:55:19 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/02 16:01:40 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_hell *my_s, int i, int s) //i и s-для экономии строчек, по норминетту 4 параметра можно
{
	int			k;
	long int	result;

	result = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-') //если встречаем -, то пишем -
			s = -1;
		i++;
	}
	k = i; //чтобы i сохранилось, i=0 если не было знака, i=1 если был - или +
	while (str[k])
	{
		if (str[k] < '0' || str[k] > '9')
			for_free(my_s, 1);
		k++;
	}
	while (str[i] > 47 && str[i] < 58)
		result = result * 10 + (str[i++] - '0'); //превращаем в int
	result = result * s;
	if (result < -2147483648 || result > 2147483647)
		for_free(my_s, 1);
	return (result);
}

void	ft_bzero(int *content, int argc)
{
	int	i;

	i = -1;
	while (++i < argc - 1) //заполняем нулями массив
		content[i] = 0;
}

int	cnt_num(int *content, int argc) //количество чисел в стеке 
{
	int	i;

	i = 0;
	while (content[i] && i < argc - 1) //content[i] перестанет существовать, если он равен 0
		i++;
	return (i);
}

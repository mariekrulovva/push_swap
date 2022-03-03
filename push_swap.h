/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:54:07 by bcriston          #+#    #+#             */
/*   Updated: 2022/03/02 15:48:36 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_hell
{
	int	*steps; //массив индексов мин пути из four[...] 
	int	*pos_in_a; //индексы места в стеке а из стека b
	int	*min_dist; //мин расстояние - количество шагов (сколько команд нужно для перекидывания из стека b в стек а)
	int	*a; //позиции в стеке incoming (с нашими числами)
	int	*b; //отсортированные позиции - главный массив
	int	*sorted; //массив отсортированных реальных поданных чисел 
	int	*incoming; //входящий массив
}	t_hell;

int		ft_atoi(char *str, t_hell *my_s, int i, int s);
void	ft_bzero(int *content, int argc);
int		cnt_num(int *content, int argc);
void	sa(t_hell *my_s, int argc);
void	sb(t_hell *my_s, int argc);
void	ss(t_hell *my_s, int argc);
void	pa(t_hell *my_s, int argc);
void	pb(t_hell *my_s, int argc);
void	ra(t_hell *my_s, int argc);
void	rb(t_hell *my_s, int argc);
void	rr(t_hell *my_s, int argc);
void	rra(t_hell *my_s, int argc);
void	rrb(t_hell *my_s, int argc);
void	rrr(t_hell *my_s, int argc);
void	sorting_incoming(t_hell *my_s, int argc);
void	fill_cont_a(t_hell *my_s, int argc);
void	pushing_to_b(t_hell *my_s, int argc);
void	algorithm2(int j, int argc, t_hell *my_s);
void	algorithm2_2(t_hell *my_s, int i, int j, int argc);
void	sravnenie(int *four, int j, t_hell *my_s);
void	func(t_hell *my_s, int i, int j, int argc);
void	if_zero(t_hell *my_s, int min_index, int argc);
void	if_one(t_hell *my_s, int min_index, int argc);
void	if_two(t_hell *my_s, int min_index, int argc);
void	if_three(t_hell *my_s, int min_index, int argc);
int		for_min_index(t_hell *my_s, int argc);
void	looking_min(t_hell *my_s, int argc);
void	check_errors(t_hell *my_s, int argc);
void	sort_3(t_hell *my_s, int argc);
void	sort_4(t_hell *my_s, int argc);
void	sort_5(t_hell *my_s, int argc);
void	sorting_min(t_hell *my_s, int argc);
void	for_malloc(t_hell *my_s, int argc);
void	for_free(t_hell *my_s, int i);
void	for_bzero1(t_hell *my_s, int argc);
void	for_bzero2(t_hell *my_s, int argc);
void	final_sort(t_hell *my_s, int argc);

#endif

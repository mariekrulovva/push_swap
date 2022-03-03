/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:36:44 by bcriston          #+#    #+#             */
/*   Updated: 2022/02/21 12:57:58 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_check
{
	int	*a;
	int	*b;
	int	len_a;
	int	len_b;
}	t_check;

int		ft_atoi(char *str, t_check *my_s);
void	ft_bzero(int *content, int argc);
int		cnt_num(int *content, int argc);
void	sa(t_check *my_s);
void	sb(t_check *my_s);
void	ss(t_check *my_s);
void	pa(t_check *my_s);
void	pb(t_check *my_s);
void	ra(t_check *my_s);
void	rb(t_check *my_s);
void	rr(t_check *my_s);
void	rra(t_check *my_s);
void	rrb(t_check *my_s);
void	rrr(t_check *my_s);
void	check_errors(t_check *my_s, int argc);
void	for_free(t_check *my_s, int i);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
void	check_command_text(t_check *my_s, int argc);
void	actions_in_stack(t_check *my_s, char *str);
void	check_sort_mas_a(t_check *my_s, int argc);
size_t	ft_strlen(const char *str);
void	for_malloc(t_check *my_s, int argc);
char	*get_next_line(int fd);

#endif

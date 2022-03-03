/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcriston <bcriston@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 13:07:38 by bcriston          #+#    #+#             */
/*   Updated: 2021/12/08 18:47:21 by bcriston         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_copy_to_line(int fd, char *buff, char *ostatok)
{
	int		simvol;
	char	*tmp;

	simvol = 1;
	while (simvol)
	{
		simvol = read(fd, buff, BUFFER_SIZE);
		if (simvol == -1)
			return (NULL);
		else if (simvol == 0)
			break ;
		if (!ostatok)
			ostatok = ft_strdup("");
		tmp = ostatok;
		buff[simvol] = '\0';
		ostatok = ft_strjoin(ostatok, buff);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (ostatok);
}

static char	*ft_ost(char *line)
{
	size_t	i;
	char	*new_ost;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	new_ost = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (*new_ost == '\0')
	{
		free(new_ost);
		new_ost = NULL;
	}
	line[i + 1] = '\0';
	return (new_ost);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*buff;
	static char	*ostatok;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (NULL);
	line = ft_copy_to_line(fd, buff, ostatok);
	free (buff);
	if (!line)
		return (NULL);
	ostatok = ft_ost(line);
	return (line);
}

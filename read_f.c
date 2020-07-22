/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:02:11 by kiskim            #+#    #+#             */
/*   Updated: 2020/07/22 20:02:13 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char			*get_info(char *file_name)
{
	char	buff[10];
	ssize_t rd_size;
	int		i;
	char	*c;
	int		file;

	if (0 > (file = open(file_name, O_RDONLY)))
		return (0);
	i = 0;
	while (0 < (rd_size = read(file, buff, sizeof(buff))))
	{
		while (buff[i])
		{
			if (buff[i] == '\n')
				break ;
			i++;
		}
		if (i > 0)
			break ;
	}
	c = malloc(sizeof(char) * i);
	c = cpy_str(buff, c);
	close(file);
	return (c);
}

int				get_x_len(int file)
{
	int		size;
	char	buff[5];
	int		i;
	int		count;
	int		flag;

	flag = 0;
	count = 0;
	while (0 < (size = read(file, buff, sizeof(buff))))
	{
		i = 0;
		while (i < 5)
		{
			if (buff[i++] == '\n')
				flag++;
			if (flag == 1)
				count++;
			if (flag == 2)
				break ;
		}
		if (flag == 2)
			break ;
	}
	close(file);
	return (count - 1);
}

map_info		set_info(char *str)
{
	map_info info;

	info.y = 0;
	while (*str >= '0' && *str <= '9')
	{
		info.y = info.y * 10 + *str - '0';
		str++;
	}
	info.empty = *str++;
	info.obst = *str++;
	info.full = *str;
	return (info);
}

map_info		file_to_struct(char *file_name)
{
	char		*c;
	int			len;
	int			file;
	map_info	info;

	c = get_info(file_name);
	len = ft_strlen(c);
	info = set_info(c);
	if (0 > (file = open(file_name, O_RDONLY)))
		return (info);
	info.x = get_x_len(file);
	if (0 > (file = open(file_name, O_RDONLY)))
		return (info);
	c = malloc(sizeof(char) * (len + 1));
	read(file, c, len + 1);
	info = set_map(file, info);
	return (info);
}

map_info		set_map(int file, map_info info)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * (info.x + 1));
	info.map = malloc(sizeof(int *) * info.y);
	while (0 < read(file, buff, info.x + 1))
	{
		info.map[i] = malloc(sizeof(int) * info.x);
		while (buff[j] != '\n')
		{
			if (buff[j] == info.empty)
				info.map[i][j] = 1;
			else if (buff[j] == info.obst)
				info.map[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (info);
}

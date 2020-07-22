#include "header.h"

char		*get_info(char *file_name)
{
	char buff[10];
	ssize_t rd_size;
	int i;
	char *c;
	int file;

	if (0 > (file = open(file_name, O_RDONLY)))
		return (0);
	i = 0;
	while (0 < ( rd_size = read(file, buff, sizeof(buff))))
	{
		while (buff[i])
		{
			if (buff[i] == '\n')
				break;
			i++;
		}
		if (i > 0)
			break;
	}
	c = malloc(sizeof(char) * i);
	c = cpy_str(buff, c);
	close(file);
	return (c);
}

int			get_x_len(char *file_name)
{
	int size;
	char buff[5];
	int i;
	int count;
	int flag;
	int file;

	if ( 0 > (file = open(file_name, O_RDONLY)))
		return (0);
	flag = 0;
	count = 0;
	while (0 < (size = read(file, buff, sizeof(buff))))
	{
		i = 0;
		while (i < 5)
		{
			if (buff[i] == '\n')
				flag++;
			if (flag == 1)
				count++;
			if (flag == 2)
				break ;
			i++;
		}
		if (flag == 2)
			break;
	}
	close(file);
	return (count - 1);
}

map_info	set_info(char *str)
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

map_info file_to_struct(char *file_name)
{
	char *c;
	int len;
	int file;
	map_info info;

	c = get_info(file_name);
	len = ft_strlen(c);
	info = set_info(c);
	info.x = get_x_len(file_name);
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
/*
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	map_info info;
	info = file_to_struct("map");
	printf("y: %d, x: %d\n", info.y, info.x);
	while (i < info.y)
	{
		j = 0;
		while (j < info.x)
		{
			printf("%d ", info.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
*/

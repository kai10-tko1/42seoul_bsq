#ifndef __DF_HD__
#define __DF_HD__

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

//tool.c
int ft_atoi(char *str);
int	ft_strlen(char *str);
char *cpy_str(char *a, char *b);

typedef struct {
	int x;
	int y;
	int **map;
	char empty;
	char obst;
	char full;
} map_info;

map_info set_map(int file, map_info info);
map_info file_to_struct(char *filename);
map_info set_info(char *str);
int get_x_len(char *file_name);
char *get_info(char *file_name);

#endif

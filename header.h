#ifndef __DF_HD__
#define __DF_HD__

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int ft_atoi(char *str);
int	ft_strlen(char *str);
typedef struct {
	int x;
	int y;
	int **map;
	char empty;
	char obst;
	char full;
} map_info;
#endif

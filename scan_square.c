#include "header.h"
#include <stdio.h>
int		compare(int a, int b, int c)
{
	a = a > b ? b : a;
	return ((a > c ? c : a) + 1);
}

int		set_max(map_info *info, int max, int i, int j)
{
	if (info->map[i][j] > max)
	{
		max = info->map[i][j];
		info->max_x = j;
		info->max_y = i;
	}
	return (max);
}

void	scan_square(map_info *info)
{
	int i;
	int j;
	int max;

	i = 1;
	max = 0;
	while (i < info->y)
	{
		j = 1;
		while (j < info->x)
		{
			if (info->map[i][j] > 0)
			{
				info->map[i][j] = compare(info->map[i - 1][j -1], 
						info->map[i - 1][j], info->map[i][j - 1]);
				max = set_max(info, max, i, j);
			}
			j++;
		}
		i++;
	}
}
#include <stdio.h>
int main()
{
	int i = 0;
	int j = 0;
	map_info info;
	info = file_to_struct("map");
	scan_square(&info);
	printf("%d %d\n", info.x, info.y);
	while (i < info.y)
	{
		j = 0;
		while(j < info.x)
		{
			printf("%d ", info.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}


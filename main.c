#include "header.h"

int main(int av, char **ac)
{
	int i = 0;
	int j = 0;

	if(av == 2)
	{	
		map_info info;
		info = file_to_struct(ac[1]);
		scan_square(&info);
		print_res(&info);
	}
	return (0);
}

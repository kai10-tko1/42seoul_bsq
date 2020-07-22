/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:03:00 by kiskim            #+#    #+#             */
/*   Updated: 2020/07/22 20:20:03 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int av, char **ac)
{
	int			i;
	int			j;
	map_info	info;

	i = 1;
	if (av > 1)
	{
		while (i < av)
		{
			info = file_to_struct(ac[i]);
			scan_square(&info);
			print_res(&info);
			i++;
		}
	}
	return (0);
}

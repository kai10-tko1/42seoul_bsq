/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:03:00 by kiskim            #+#    #+#             */
/*   Updated: 2020/07/22 20:04:51 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int av, char **ac)
{
	int			i;
	int			j;
	map_info	info;

	i = 0;
	j = 0;
	if (av == 2)
	{
		info = file_to_struct(ac[1]);
		scan_square(&info);
		print_res(&info);
	}
	return (0);
}

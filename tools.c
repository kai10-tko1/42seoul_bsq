/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kiskim <kiskim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 20:07:13 by kiskim            #+#    #+#             */
/*   Updated: 2020/07/22 20:08:53 by kiskim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(char *s)
{
	int res;
	int i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + s[i] - '0';
		else
			break ;
		i++;
	}
	return (res);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*cpy_str(char *a, char *b)
{
	int i;

	i = 0;
	while (a[i] != '\n')
	{
		b[i] = a[i];
		i++;
	}
	b[i] = '\0';
	return (b);
}

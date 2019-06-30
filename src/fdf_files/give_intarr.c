/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_intarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:11:04 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/28 15:11:05 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_number_rows(t_map *lst)
{
	int		rows;

	rows = 0;
	while (lst->str[rows] != NULL)
		rows++;
	return (rows);
}

int		ft_number_columns(t_map *lst)
{
	int		columns;

	columns = 0;
	while (lst != NULL)
	{
		columns++;
		lst = lst->next;
	}
	return (columns);
}

void	ft_change_coor(t_linedraw line)
{
	int		i;
	int		j;

	j = 0;
	while (j < line.m)
	{
		i = 0;
		while (i < line.n)
		{
			line.coor[j][i].x -= (long double)(line.n / 2);
			line.coor[j][i].y -= (long double)(line.m / 2);
			i++;
		}
		j++;
	}
}

t_coor	**give_coor(t_map *lst)
{
	t_coor	**arr;
	int		n;
	int		m;
	int		i;
	int		j;

	j = 0;
	n = ft_number_rows(lst);
	m = ft_number_columns(lst);
	arr = (t_coor**)malloc(sizeof(*arr) * m);
	while (j < m)
	{
		i = 0;
		arr[j] = (t_coor*)malloc(sizeof(t_coor) * n);
		while (i < n)
		{
			arr[j][i].x = i;
			arr[j][i].y = j;
			arr[j][i].z = (long double)(ft_atoi(lst->str[i]));
			i++;
		}
		lst = lst->next;
		j++;
	}
	return (arr);
}

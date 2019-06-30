/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_coor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 15:23:35 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/07 15:23:36 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_x(t_linedraw *line, int sign)
{
	long double	y;
	long double	z;
	int			j;
	int			i;

	(*line).degree += (long double)(5 * M_PI / 180 * sign);
	j = 0;
	while (j < (*line).m)
	{
		i = 0;
		while (i < (*line).n)
		{
			y = (*line).coor[j][i].y;
			z = (*line).coor[j][i].z;
			(*line).coor[j][i].y = y * cosl((*line).degree) -
									z * sinl((*line).degree);
			(*line).coor[j][i].z = y * sinl((*line).degree) +
									z * cosl((*line).degree);
			i++;
		}
		j++;
	}
	ft_draw_map(line);
}

void	ft_rotate_y(t_linedraw *line, int sign)
{
	long double	x;
	long double	z;
	int			j;
	int			i;

	(*line).degree += (long double)(5 * M_PI / 180 * sign);
	j = 0;
	while (j < (*line).m)
	{
		i = 0;
		while (i < (*line).n)
		{
			x = (*line).coor[j][i].x;
			z = (*line).coor[j][i].z;
			(*line).coor[j][i].x = x * cosl((*line).degree) +
									z * sinl((*line).degree);
			(*line).coor[j][i].z = z * cosl((*line).degree) -
									x * sinl((*line).degree);
			i++;
		}
		j++;
	}
	ft_draw_map(line);
}

void	ft_rotate_z(t_linedraw *line, int sign)
{
	long double	x;
	long double	y;
	int			j;
	int			i;

	(*line).degree += (long double)(5 * M_PI / 180 * sign);
	j = 0;
	while (j < (*line).m)
	{
		i = 0;
		while (i < (*line).n)
		{
			x = (long double)(*line).coor[j][i].x;
			y = (long double)(*line).coor[j][i].y;
			(*line).coor[j][i].x = x * cosl((*line).degree) -
									y * sinl((*line).degree);
			(*line).coor[j][i].y = x * sinl((*line).degree) +
									y * cosl((*line).degree);
			i++;
		}
		j++;
	}
	ft_draw_map(line);
}

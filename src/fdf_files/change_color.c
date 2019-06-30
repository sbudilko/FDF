/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:44:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/07 18:44:32 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_change_color2(t_linedraw *line, int x)
{
	if (x >= 1680 && x <= 1720)
		(*line).color = (*line).arr[9];
	else if (x >= 1820 && x <= 1860)
		(*line).color = (*line).arr[10];
	else if (x >= 1960 && x <= 2000)
		(*line).color = (*line).arr[11];
	else if (x >= 2100 && x <= 2140)
		(*line).color = (*line).arr[12];
	ft_draw_map(line);
}

void	ft_change_color(t_linedraw *line, int x, int y)
{
	if (y >= 1160 && y <= 1200)
	{
		if (x >= 420 && x <= 460)
			(*line).color = (*line).arr[0];
		else if (x >= 560 && x <= 600)
			(*line).color = (*line).arr[1];
		else if (x >= 700 && x <= 740)
			(*line).color = (*line).arr[2];
		else if (x >= 840 && x <= 880)
			(*line).color = (*line).arr[3];
		else if (x >= 980 && x <= 1020)
			(*line).color = (*line).arr[4];
		else if (x >= 1120 && x <= 1160)
			(*line).color = (*line).arr[5];
		else if (x >= 1260 && x <= 1300)
			(*line).color = (*line).arr[6];
		else if (x >= 1400 && x <= 1440)
			(*line).color = (*line).arr[7];
		else if (x >= 1540 && x <= 1580)
			(*line).color = (*line).arr[8];
		else
			ft_change_color2(line, x);
		ft_draw_map(line);
	}
}

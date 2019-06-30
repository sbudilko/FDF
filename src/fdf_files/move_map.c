/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:19:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/07 16:19:38 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_check_coor(int x, int y)
{
	if (x <= 390 || x >= WIDTH - 60)
	{
		if (x >= 30)
			return (-1);
		return (0);
	}
	if (y <= 150 || y >= 1080)
	{
		if (y >= 60)
			return (-1);
		return (0);
	}
	return (1);
}

void	ft_move_map(t_linedraw *line, int direction)
{
	if (direction == 1)
		(*line).ver -= 10;
	else if (direction == 2)
		(*line).ver += 10;
	else if (direction == 3)
		(*line).hor += 10;
	else if (direction == 4)
		(*line).hor -= 10;
	else
	{
		(*line).hor = 0;
		(*line).ver = 0;
	}
	ft_draw_map(line);
}

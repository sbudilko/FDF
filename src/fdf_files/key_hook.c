/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:42:47 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/06 16:42:49 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		close_click_exit(void)
{
	exit(1);
}

void	key_handler2(int key, t_linedraw *line)
{
	if (key == 78)
	{
		(*line).k -= 0.5;
		ft_draw_map(line);
	}
	else if (key == 91)
		ft_move_map(line, 1);
	else if (key == 84)
		ft_move_map(line, 2);
	else if (key == 88)
		ft_move_map(line, 3);
	else if (key == 86)
		ft_move_map(line, 4);
	else if (key == 87)
		ft_move_map(line, 5);
	else if (key == 18)
	{
		(*line).axis = 1;
		ft_draw_map(line);
	}
	else if (key == 29)
	{
		(*line).axis = 0;
		ft_draw_map(line);
	}
}

int		key_handler(int key, t_linedraw *line)
{
	line->degree = 0;
	if (key == 53)
		exit(0);
	else if (key == 126)
		ft_rotate_x(line, 1);
	else if (key == 125)
		ft_rotate_x(line, -1);
	else if (key == 124)
		ft_rotate_y(line, 1);
	else if (key == 123)
		ft_rotate_y(line, -1);
	else if (key == 2)
		ft_rotate_z(line, 1);
	else if (key == 0)
		ft_rotate_z(line, -1);
	else if (key == 69)
	{
		(*line).k += 0.5;
		ft_draw_map(line);
	}
	else
		key_handler2(key, line);
	return (0);
}

int		mause_handler(int key, int x, int y, t_linedraw *line)
{
	(*line).degree = 0;
	if (key == 1)
		ft_change_color(line, x, y);
	return (0);
}

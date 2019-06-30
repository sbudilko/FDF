/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_line_algorithm.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:57:52 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/26 13:57:58 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_bresenham_4(t_linedraw line)
{
	int		dx;
	int		dy;
	int		error;

	dx = fabsl(line.endpoint.y - line.startpoint.y);
	dy = fabsl(line.endpoint.x - line.startpoint.x);
	error = 2 * dy - dx;
	while (line.startpoint.y >= line.endpoint.y)
	{
		if (ft_check_coor(line.endpoint.x, line.endpoint.y) == 0)
			return ;
		if (ft_check_coor(line.endpoint.x, line.endpoint.y) == 1)
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, line.endpoint.x,
						line.endpoint.y, line.color);
		if (error > 0)
		{
			error += 2 * dy - 2 * dx;
			line.endpoint.x--;
		}
		else
			error += 2 * dy;
		line.endpoint.y++;
	}
}

void	ft_bresenham_3(t_linedraw line)
{
	int		dx;
	int		dy;
	int		error;

	dx = fabsl(line.endpoint.x - line.startpoint.x);
	dy = fabsl(line.endpoint.y - line.startpoint.y);
	error = 2 * dy - dx;
	while (line.startpoint.x <= line.endpoint.x)
	{
		if (ft_check_coor(line.endpoint.x, line.endpoint.y) == 0)
			return ;
		if (ft_check_coor(line.endpoint.x, line.endpoint.y) == 1)
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, line.endpoint.x,
						line.endpoint.y, line.color);
		if (error > 0)
		{
			error += 2 * dy - 2 * dx;
			line.endpoint.y++;
		}
		else
			error += 2 * dy;
		line.endpoint.x--;
	}
}

void	ft_bresenham_2(t_linedraw line)
{
	int		dx;
	int		dy;
	int		error;

	dx = fabsl(line.endpoint.y - line.startpoint.y);
	dy = fabsl(line.endpoint.x - line.startpoint.x);
	error = 2 * dy - dx;
	while (line.startpoint.y <= line.endpoint.y)
	{
		if (ft_check_coor(line.startpoint.x, line.startpoint.y) == 0)
			return ;
		if (ft_check_coor(line.startpoint.x, line.startpoint.y) == 1)
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, line.startpoint.x,
					line.startpoint.y, line.color);
		if (error > 0)
		{
			error += 2 * dy - 2 * dx;
			line.startpoint.x++;
		}
		else
			error += 2 * dy;
		line.startpoint.y++;
	}
}

void	ft_bresenham_1(t_linedraw line)
{
	int		dx;
	int		dy;
	int		error;

	dx = fabsl(line.endpoint.x - line.startpoint.x);
	dy = fabsl(line.endpoint.y - line.startpoint.y);
	error = 2 * dy - dx;
	while (line.startpoint.x <= line.endpoint.x)
	{
		if (ft_check_coor(line.startpoint.x, line.startpoint.y) == 0)
			return ;
		if (ft_check_coor(line.startpoint.x, line.startpoint.y) == 1)
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, line.startpoint.x,
					line.startpoint.y, line.color);
		if (error > 0)
		{
			error += 2 * dy - 2 * dx;
			line.startpoint.y++;
		}
		else
			error += 2 * dy;
		line.startpoint.x++;
	}
}

void	ft_bresenham(t_linedraw line)
{
	int		dx;
	int		dy;
	int		buff;

	if (line.endpoint.x < line.startpoint.x)
	{
		buff = line.endpoint.x;
		line.endpoint.x = line.startpoint.x;
		line.startpoint.x = buff;
		buff = line.endpoint.y;
		line.endpoint.y = line.startpoint.y;
		line.startpoint.y = buff;
	}
	dx = line.endpoint.x - line.startpoint.x;
	dy = line.endpoint.y - line.startpoint.y;
	if (abs(dx) >= abs(dy) && dy >= 0)
		ft_bresenham_1(line);
	else if (abs(dx) < abs(dy) && dy > 0)
		ft_bresenham_2(line);
	else if (abs(dx) >= abs(dy) && dy < 0)
		ft_bresenham_3(line);
	else
		ft_bresenham_4(line);
}

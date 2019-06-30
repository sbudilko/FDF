/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 11:35:13 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/29 11:35:15 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_draw_columns(t_linedraw line)
{
	int		x;
	int		y;

	y = 0;
	while (y < line.m)
	{
		x = 0;
		while (x < line.n - 1)
		{
			line.startpoint.x = line.coor[y][x].x * line.k + 1445 +
								line.hor;
			line.startpoint.y = line.coor[y][x].y * line.k + 615 +
								line.ver;
			line.endpoint.x = line.coor[y][x + 1].x * line.k + 1445 +
								line.hor;
			line.endpoint.y = line.coor[y][x + 1].y * line.k + 615 +
								line.ver;
			ft_bresenham(line);
			x++;
		}
		y++;
	}
}

void	ft_draw_rows(t_linedraw line)
{
	int		x;
	int		y;

	x = 0;
	while (x < line.n)
	{
		y = 0;
		while (y < line.m - 1)
		{
			line.startpoint.x = line.coor[y][x].x * line.k + 1445 +
								line.hor;
			line.startpoint.y = line.coor[y][x].y * line.k + 615 +
								line.ver;
			line.endpoint.x = line.coor[y + 1][x].x * line.k + 1445 +
								line.hor;
			line.endpoint.y = line.coor[y + 1][x].y * line.k + 615 +
								line.ver;
			ft_bresenham(line);
			y++;
		}
		x++;
	}
}

void	ft_draw_map(t_linedraw *line)
{
	mlx_clear_window((*line).mlx_ptr, (*line).win_ptr);
	ft_draw_interface(line);
	ft_draw_columns((*line));
	ft_draw_rows((*line));
	if ((*line).axis == 1)
		draw_axis((*line));
}

void	ft_setup_linedraw(t_map **lst, t_linedraw *line)
{
	(*line).coor = give_coor(*lst);
	(*line).mlx_ptr = mlx_init();
	(*line).win_ptr = mlx_new_window((*line).mlx_ptr, WIDTH, HEIGHT, "TEST");
	(*line).m = ft_number_columns(*lst);
	(*line).n = ft_number_rows(*lst);
	(*line).k = ft_scale((*line).m, (*line).n);
	(*line).axis = 0;
	ft_change_coor(*line);
	(*line).color = 0xf0f8ff;
	(*line).hor = 0;
	(*line).ver = 0;
	ft_dellst_map(*lst);
	*lst = NULL;
}

void	ft_draw(t_map **lst)
{
	t_linedraw		line;

	ft_setup_linedraw(lst, &line);
	ft_draw_map(&line);
	mlx_hook(line.win_ptr, 17, 1L << 17, close_click_exit, &line);
	mlx_hook(line.win_ptr, 2, 1L << 0, key_handler, &line);
	mlx_hook(line.win_ptr, 4, 0, mause_handler, &line);
	mlx_loop(line.mlx_ptr);
}

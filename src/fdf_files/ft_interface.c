/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_interface.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 16:42:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/06 16:42:37 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_bar(t_linedraw line)
{
	int		x;
	int		y;

	y = 0;
	while (y < 90)
	{
		x = 0;
		while (x <= 2560)
		{
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, y, 0x0f544f);
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, HEIGHT - y, 0x0f544f);
			x++;
		}
		y++;
	}
	x = 0;
	while (x <= 2560)
	{
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, y, 0xffe4e1);
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, HEIGHT - y, 0xffe4e1);
		x++;
	}
}

void	ft_draw_square(t_linedraw line, int x, int y, int color)
{
	int i;
	int j;

	j = 0;
	while (j <= 40)
	{
		i = 0;
		while (i <= 40)
		{
			mlx_pixel_put(line.mlx_ptr, line.win_ptr, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

void	ft_draw_color(t_linedraw *line)
{
	int		i;
	int		x;

	i = 0;
	x = 420;
	(*line).arr[0] = 0xb6fcd5;
	(*line).arr[1] = 0x00ff7f;
	(*line).arr[2] = 0x9ac066;
	(*line).arr[3] = 0x6d8d5c;
	(*line).arr[4] = 0x0f544f;
	(*line).arr[5] = 0xd08a8a;
	(*line).arr[6] = 0xcf3821;
	(*line).arr[7] = 0x941414;
	(*line).arr[8] = 0x6495ed;
	(*line).arr[9] = 0x0349ca;
	(*line).arr[10] = 0xffff00;
	(*line).arr[11] = 0xff00ff;
	(*line).arr[12] = 0xcc0099;
	while (i < 13)
	{
		ft_draw_square(*line, x, 1160, (*line).arr[i]);
		i++;
		x += 140;
	}
}

void	draw_frame(t_linedraw line)
{
	int		y;
	int		x;

	y = 140;
	x = 380;
	while (y <= 1090)
	{
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, 380, y, 0xd6ff94);
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, WIDTH - 50, y, 0xd6ff94);
		y++;
	}
	while (x <= WIDTH - 50)
	{
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, 140, 0xd6ff94);
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, 1090, 0xd6ff94);
		x++;
	}
}

void	ft_draw_interface(t_linedraw *line)
{
	int	x;

	x = 0;
	ft_draw_bar((*line));
	while (x <= WIDTH)
	{
		mlx_pixel_put((*line).mlx_ptr, (*line).win_ptr, x, 1140, 0xffe4e1);
		x++;
	}
	x = 91;
	while (x < 1140)
	{
		mlx_pixel_put((*line).mlx_ptr, (*line).win_ptr, 330, x, 0xffe4e1);
		x++;
	}
	draw_frame((*line));
	ft_draw_color(line);
	ft_print_legend(line);
}

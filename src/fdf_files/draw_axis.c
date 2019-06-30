/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_axis.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:11:50 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/07 16:12:08 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_scale(int m, int n)
{
	int		k;

	k = 0;
	while (n * k < 1800)
		k++;
	if (m * k >= 800)
		while (m * k >= 800)
			k--;
	return (k);
}

void	draw_axis(t_linedraw line)
{
	int y;
	int x;

	x = 380;
	y = 615;
	while (x <= WIDTH - 50)
	{
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, y, 0xffff00);
		x++;
	}
	x = 1445;
	y = 141;
	while (y <= 1090)
	{
		mlx_pixel_put(line.mlx_ptr, line.win_ptr, x, y, 0xffff00);
		y++;
	}
}

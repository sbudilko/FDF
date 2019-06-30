/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_legend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 20:01:31 by sbudilko          #+#    #+#             */
/*   Updated: 2018/07/07 20:01:34 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	ft_print_legend(t_linedraw *line)
{
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 140 + 150, 0xffffff,
					"Zoom in           : +");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 160 + 150, 0xffffff,
					"Zoom in           : -");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 200 + 150, 0xffffff,
					"Move Left         : NUM4");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 220 + 150, 0xffffff,
					"Move Right        : NUM6");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 240 + 150, 0xffffff,
					"Move Up           : NUM8");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 260 + 150, 0xffffff,
					"Move Down         : NUM2");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 280 + 150, 0xffffff,
					"Aligned by Centre : NUM5");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 320 + 150, 0xffffff,
					"Rotate by X       : <-,->");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 340 + 150, 0xffffff,
					"Rotate by Y       : Up, Down");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 360 + 150, 0xffffff,
					"Rotate by Z       : A,D");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 400 + 150, 0xffffff,
					"Show Axises       : 1");
	mlx_string_put((*line).mlx_ptr, (*line).win_ptr, 30, 420 + 150, 0xffffff,
					"Hide Axises       : 0");
}

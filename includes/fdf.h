/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:50:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/26 13:50:32 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <math.h>
# include "ft_printf.h"
# include "mlx.h"
# define WIDTH 2560
# define HEIGHT 1310

typedef struct		s_coor
{
	long double		x;
	long double		y;
	long double		z;
}					t_coor;

typedef struct		s_linedraw
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				arr[13];
	int				color;
	int				ver;
	int				hor;
	long double		k;
	int				m;
	int				n;
	int				axis;
	long double		degree;
	t_coor			startpoint;
	t_coor			endpoint;
	t_coor			**coor;
}					t_linedraw;

typedef	struct		s_map
{
	char			**str;
	struct s_map	*next;
}					t_map;

void				ft_bresenham(t_linedraw line);

void				ft_dellst_map(t_map *lst);
int					ft_parse_map(int fd, t_map **lst);
int					ft_validation_map(t_map *lst);

t_coor				**give_coor(t_map *lst);
void				ft_change_coor(t_linedraw line);

int					ft_number_rows(t_map *lst);
int					ft_number_columns(t_map *lst);

void				ft_draw(t_map **lst);
void				ft_draw_map(t_linedraw *line);
void				ft_draw_interface(t_linedraw *line);
void				draw_axis(t_linedraw line);
void				ft_print_legend(t_linedraw *line);

int					key_handler(int key, t_linedraw *line);
int					mause_handler(int key, int x, int y, t_linedraw *line);
int					close_click_exit(void);

void				ft_rotate_x(t_linedraw *line, int sign);
void				ft_rotate_y(t_linedraw *line, int sign);
void				ft_rotate_z(t_linedraw *line, int sign);

int					ft_check_coor(int x, int y);
int					ft_scale(int m, int n);
void				ft_change_color(t_linedraw *line, int x, int y);
void				ft_move_map(t_linedraw *line, int direction);

#endif

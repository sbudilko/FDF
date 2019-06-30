/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 14:26:30 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/26 14:26:31 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*lst;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf <filename> [ case_size z_size ]");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (ft_parse_map(fd, &lst) == -1)
		return (0);
	close(fd);
	if (ft_validation_map(lst) == -1)
		ft_putendl("Found wrong line length. Exiting.");
	ft_draw(&lst);
	return (0);
}

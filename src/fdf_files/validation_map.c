/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 13:25:50 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/28 13:25:52 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_validation_map(t_map *lst)
{
	t_map	*lst_buff;
	int		rows;
	int		i;
	char	**s;

	rows = 0;
	s = lst->str;
	lst_buff = lst;
	while (s[rows] != NULL)
		rows++;
	lst_buff = lst_buff->next;
	while (lst_buff != NULL)
	{
		i = 0;
		while (s[i] != NULL)
			i++;
		if (rows != i)
			return (-1);
		lst_buff = lst_buff->next;
	}
	return (rows);
}

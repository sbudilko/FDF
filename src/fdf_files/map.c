/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbudilko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 16:06:53 by sbudilko          #+#    #+#             */
/*   Updated: 2018/06/28 16:06:54 by sbudilko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_delone_map(t_map *lst)
{
	int		i;

	i = 0;
	while (lst->str[i] != NULL)
	{
		free(lst->str[i]);
		lst->str[i] = NULL;
		i++;
	}
	free(lst->str);
	lst->str = NULL;
	free(lst);
	lst = NULL;
}

void	ft_dellst_map(t_map *lst)
{
	if (lst->next != NULL)
		ft_dellst_map(lst->next);
	ft_delone_map(lst);
}

t_map	*ft_newlst_map(char *str)
{
	t_map	*lst;

	lst = (t_map*)malloc(sizeof(t_map));
	lst->str = ft_strsplit(str, ' ');
	lst->next = NULL;
	return (lst);
}

void	ft_addlst_map(t_map *lst, char *str)
{
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = ft_newlst_map(str);
}

int		ft_parse_map(int fd, t_map **lst)
{
	int		i;
	char	*str;

	i = get_next_line(fd, &str);
	if (i == 0 || i == -1)
	{
		if (i == 0)
			ft_putendl("No data foud.");
		else
			ft_putendl("Bad file descriptor");
		return (-1);
	}
	*lst = ft_newlst_map(str);
	free(str);
	while (i != 0)
	{
		i = get_next_line(fd, &str);
		if (i != 0)
		{
			ft_addlst_map(*lst, str);
			free(str);
		}
	}
	return (1);
}

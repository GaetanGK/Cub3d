/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 16:28:02 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/08/12 16:28:04 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_swap_line(char **line, char *temp)
{
	if (*line)
		temp = *line;
}

int	ft_gnl_cpy(int ret, char *buff, char **line)
{
	while (ret > 0)
	{
		buff[ret] = '\0';
		if (!ft_copy(line, &buff))
			return (1);
	}
	return (0);
}

void	ft_map_copy(t_datar *recup, char *str)
{
	if (recup->insidemap == 1)
	{
		recup->count++;
		ft_copy_map(str, recup);
	}
}

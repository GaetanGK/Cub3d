/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:39:48 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/09 16:39:50 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_map_has_wall_at(t_datar *data, float x, float y)
{
	int	map_grid_x;
	int	map_grid_y;

	if (x < 0 || x >= data->sizeline * TILE_SIZE || y < 0
		|| y >= data->nblines * TILE_SIZE)
		return (1);
	map_grid_x = floor(x / TILE_SIZE);
	map_grid_y = floor(y / TILE_SIZE);
	return (data->map[map_grid_y][map_grid_x] != 0);
}

int	ft_test_str(char i)
{
	if (i != ' ' && i != '\t' && i != ',' && i != '\n' && i != '\r'
		&& i != '\v' && i != '\f')
		return (1);
	return (0);
}

int	ft_test_str2(char str)
{
	if (str == ' ' || str == '\t' || str == ',' || str == '\n' || str == '\r'
		|| str == '\v' || str == '\f')
		return (1);
	return (0);
}

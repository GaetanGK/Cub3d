/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glich_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 12:10:50 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/11/08 12:10:55 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_glitch45(t_datar *data, int map_grid_x, int map_grid_y)
{
	if (data->player.rotation_angle > 0 && data->player.rotation_angle
		<= MY_PI / 2 && data->map[map_grid_x + 1][map_grid_y] != 0
		&& data->map[map_grid_x][map_grid_y + 1] != 0
		&& (fmod(data->player.y, TILE_SIZE) > 50
			&& fmod(data->player.x, TILE_SIZE) > 50))
		return (1);
	return (0);
}

int	ft_glitch135(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > MY_PI / 2
			&& data->player.rotation_angle
			<= MY_PI) && data->map[map_grid_x][map_grid_y - 1] != 0
		&& data->map[map_grid_x + 1][map_grid_y] != 0
		&& (fmod(data->player.y, TILE_SIZE) > 50
			&& fmod(data->player.x, TILE_SIZE) < 10))
		return (1);
	return (0);
}

int	ft_glitch225(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > MY_PI && data->player.rotation_angle
			<= MY_PI + (MY_PI / 2 )) && data->map[map_grid_x]
		[map_grid_y - 1] != 0 && data->map[map_grid_x - 1][map_grid_y] != 0
		&& (fmod(data->player.y, TILE_SIZE) < 10
			&& fmod(data->player.x, TILE_SIZE) < 10))
		return (1);
	return (0);
}

int	ft_glitch315(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > MY_PI + (MY_PI / 2 )
			&& data->player.rotation_angle <= MY_TWO_PI) && data->map
		[map_grid_x][map_grid_y + 1] != 0 && data->map[map_grid_x - 1]
		[map_grid_y] != 0 && (fmod(data->player.y, TILE_SIZE) < 10
			&& fmod(data->player.x, TILE_SIZE) > 10))
		return (1);
	return (0);
}

int	ft_glitch(t_datar *data)
{
	int	map_grid_x;
	int	map_grid_y;

	map_grid_x = floor(data->player.y / TILE_SIZE);
	map_grid_y = floor(data->player.x / TILE_SIZE);
	if (data->player.walk_direction == 1)
	{
		if (ft_glitch45(data, map_grid_x, map_grid_y))
			return (1);
		if (ft_glitch135(data, map_grid_x, map_grid_y))
			return (1);
		if (ft_glitch225(data, map_grid_x, map_grid_y))
			return (1);
		if (ft_glitch315(data, map_grid_x, map_grid_y))
			return (1);
	}
	else if (data->player.walk_direction == -1)
	{
		if (ft_glitch_inverse(data, map_grid_x, map_grid_y))
			return (1);
	}
	return (0);
}

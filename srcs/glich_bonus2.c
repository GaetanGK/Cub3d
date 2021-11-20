/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   glich_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:00:55 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/11/08 14:00:56 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_glitch045(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > MY_PI && data->player.rotation_angle
			<= MY_PI + (MY_PI / 2 )) && data->map[map_grid_x + 1]
		[map_grid_y] != 0 && data->map[map_grid_x][map_grid_y + 1] != 0
		&& (fmod(data->player.y, TILE_SIZE) > 50
			&& fmod(data->player.x, TILE_SIZE) > 50))
		return (1);
	return (0);
}

int	ft_glitch0135(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > MY_PI + (MY_PI / 2 )
			&& data->player.rotation_angle <= MY_TWO_PI)
		&& data->map[map_grid_x][map_grid_y - 1] != 0
		&& data->map[map_grid_x + 1][map_grid_y] != 0
		&& (fmod(data->player.y, TILE_SIZE) > 50
			&& fmod(data->player.x, TILE_SIZE) < 10))
		return (1);
	return (0);
}

int	ft_glitch0225(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > 0 && data->player.rotation_angle
			<= (MY_PI / 2 )) && data->map[map_grid_x]
		[map_grid_y - 1] != 0 && data->map[map_grid_x - 1][map_grid_y] != 0
		&& (fmod(data->player.y, TILE_SIZE) < 10
			&& fmod(data->player.x, TILE_SIZE) < 10))
		return (1);
	return (0);
}

int	ft_glitch0315(t_datar *data, int map_grid_x, int map_grid_y)
{
	if ((data->player.rotation_angle > (MY_PI / 2 )
			&& data->player.rotation_angle <= MY_PI) && data->map
		[map_grid_x][map_grid_y + 1] != 0 && data->map[map_grid_x - 1]
		[map_grid_y] != 0 && (fmod(data->player.y, TILE_SIZE) < 10
			&& fmod(data->player.x, TILE_SIZE) > 10))
		return (1);
	return (0);
}

int	ft_glitch_inverse(t_datar *data, int map_grid_x, int map_grid_y)
{
	if (ft_glitch045(data, map_grid_x, map_grid_y))
		return (1);
	if (ft_glitch0135(data, map_grid_x, map_grid_y))
		return (1);
	if (ft_glitch0225(data, map_grid_x, map_grid_y))
		return (1);
	if (ft_glitch0315(data, map_grid_x, map_grid_y))
		return (1);
	return (0);
}

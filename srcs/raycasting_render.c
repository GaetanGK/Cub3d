/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_render.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 16:04:44 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/09 16:04:46 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_render_background(t_datar *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			ft_img_pix_put(&data->img, j++, i, color);
		}
		++i;
	}
}

void	ft_render_player(t_datar *data)
{
	t_line	line;

	line.begin_x = MINIMAP_SCALE_FACTOR * data->player.x
		+ cos(data->player.rotation_angle) * 20;
	line.begin_y = MINIMAP_SCALE_FACTOR * data->player.y
		+ sin(data->player.rotation_angle) * 20;
	line.end_x = data->player.x * MINIMAP_SCALE_FACTOR;
	line.end_y = data->player.y * MINIMAP_SCALE_FACTOR;
	line.color = 0xFF0000;
	ft_render_rect(&data->img, (t_rect){data->player.x * MINIMAP_SCALE_FACTOR,
		data->player.y * MINIMAP_SCALE_FACTOR, data->player.width
		* MINIMAP_SCALE_FACTOR, data->player.height
		* MINIMAP_SCALE_FACTOR, 0xFFFFFF});
}

void	ft_render_map(t_datar *data)
{
	int		i;
	int		j;
	t_rect	rect2;

	i = 0;
	while (i < data->nblines)
	{
		j = 0;
		while (j < data->sizeline)
		{
			rect2.x = j * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			rect2.y = i * TILE_SIZE * MINIMAP_SCALE_FACTOR;
			if (data->map[i][j] != 0)
				rect2.color = 0xFFFFFF;
			else
				rect2.color = 0X000000;
			rect2.width = TILE_SIZE * MINIMAP_SCALE_FACTOR;
			rect2.height = TILE_SIZE * MINIMAP_SCALE_FACTOR;
			if (rect2.x <= WINDOW_WIDTH && rect2.y <= WINDOW_HEIGHT)
				ft_render_rect(&data->img, rect2);
			j++;
		}
		++i;
	}
}

void	ft_render_rays(t_datar *data)
{
	t_line	rays_line;
	int		i;

	i = 0;
	while (i < (NUM_RAYS - 80))
	{
		rays_line.begin_x = MINIMAP_SCALE_FACTOR * data->rays[i].wall_hit_x;
		rays_line.begin_y = MINIMAP_SCALE_FACTOR * data->rays[i].wall_hit_y;
		rays_line.end_x = data->player.x * MINIMAP_SCALE_FACTOR;
		rays_line.end_y = data->player.y * MINIMAP_SCALE_FACTOR;
		rays_line.color = 0xFF00;
		ft_draw_line(&data->img, rays_line);
		i += 20;
	}
}

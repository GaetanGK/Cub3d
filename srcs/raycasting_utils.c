/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:52:21 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/09 13:52:22 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

float	ft_dist_bet_points(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_normalize_angle(float *angle)
{
	*angle = remainder(*angle, MY_TWO_PI);
	if (*angle < 0)
	{
		*angle = *angle + MY_TWO_PI;
	}
}

void	ft_render_wall(t_datar *data)
{
	t_render	render;
	int			i;

	render.text_num = 0;
	render.perp_distance = 0;
	render.dist_proj_plane = 0;
	render.proj_wall_height = 0;
	render.wall_strip_height = 0;
	render.wall_top_pixel = 0;
	render.wall_bottom_pixel = 0;
	render.dist_from_top = 0;
	render.texture_offset_y = 0;
	render.texel_color = NULL;
	render.texture_offset_x = 0;
	i = 0;
	while (i < NUM_RAYS)
	{
		ft_render_wall_setup(data, &render, i);
		ft_f_c_pix_put(data, i);
		ft_texture_setup(data, &render, i);
		ft_wall_pix_put(data, &render, i);
		i++;
	}
}

void	ft_cast_ray(t_datar *data, float ray_angle, int strip_id)
{
	t_cast	ray;

	ft_normalize_angle(&ray_angle);
	ft_cast_ray_init(data, &ray, ray_angle);
	ft_cast_ray_init_next(data, &ray, ray_angle);
	ft_horz_touch(data, &ray);
	ft_vert_touch(data, &ray, ray_angle);
	if (ray.found_horz_wall_hit)
		ray.horz_hit_dist = ft_dist_bet_points(data->player.x, data->player.y,
				ray.horzwall_hit_x, ray.horzwall_hit_y);
	else
		ray.horz_hit_dist = FLT_MAX;
	if (ray.found_vert_wall_hit)
		ray.vert_hit_dist = ft_dist_bet_points(data->player.x, data->player.y,
				ray.vert_wall_hit_x, ray.vert_wall_hit_y);
	else
		ray.vert_hit_dist = FLT_MAX;
	ft_data_rays(data, &ray, ray_angle, strip_id);
}

void	ft_cast_rays(t_datar *data)
{
	float	dist_proj_plane;
	float	ray_angle;
	int		col;

	col = 0;
	dist_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (col < NUM_RAYS)
	{
		ray_angle = data->player.rotation_angle
			+ atan((col - NUM_RAYS / 2) / dist_proj_plane);
		ft_cast_ray(data, ray_angle, col);
		col++;
	}
}

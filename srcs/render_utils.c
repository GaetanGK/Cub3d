/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 18:42:41 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/07/22 18:42:43 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

void	ft_render_wall_setup(t_datar *data, t_render *render, int i)
{
	render->perp_distance = data->rays[i].distance
		* cos(data->rays[i].ray_angle
			- data->player.rotation_angle);
	render->dist_proj_plane = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	render->proj_wall_height = (TILE_SIZE / render->perp_distance)
		* render->dist_proj_plane;
	render->wall_strip_height = (int)render->proj_wall_height;
	render->wall_top_pixel = (WINDOW_HEIGHT / 2)
		- (render->wall_strip_height / 2);
	if (render->wall_top_pixel < 0)
		render->wall_top_pixel = 0;
	render->wall_bottom_pixel = (WINDOW_HEIGHT / 2)
		+ (render->wall_strip_height / 2);
	if (render->wall_bottom_pixel > WINDOW_HEIGHT)
		render->wall_bottom_pixel = WINDOW_HEIGHT;
}

void	ft_wall_pix_put(t_datar *data, t_render *render, int i)
{
	int	y;

	y = render->wall_top_pixel;
	while (y < render->wall_bottom_pixel)
	{
		render->dist_from_top = y + (render->wall_strip_height / 2)
			- (WINDOW_HEIGHT / 2);
		render->texture_offset_y = render->dist_from_top
			* ((float)data->texture[0].height / render->wall_strip_height);
		render->texel_color = data->texture[render->text_num].addr
			+ (render->texture_offset_y * data->texture[render->text_num
			].line_len + render->texture_offset_x * (data->texture
				[render->text_num].bpp / 8));
		ft_img_pix_put(&data->img, i, y, *(int *)render->texel_color);
		y++;
	}
}

void	ft_texture_setup(t_datar *data, t_render *render, int i)
{
	if (data->rays[i].was_hit_vert)
		render->texture_offset_x = (int)data->rays[i].wall_hit_y % TILE_SIZE;
	else
		render->texture_offset_x = (int)data->rays[i].wall_hit_x % TILE_SIZE;
	if (data->rays[i].was_hit_vert && data->rays[i].is_ray_facing_left)
		render->text_num = 0;
	else if (data->rays[i].was_hit_vert && data->rays[i].is_ray_facing_right)
		render->text_num = 1;
	else if (!data->rays[i].was_hit_vert && data->rays[i].is_ray_facing_up)
		render->text_num = 2;
	else if (!data->rays[i].was_hit_vert
		&& data->rays[i].is_ray_facing_down)
		render->text_num = 3;
}

void	ft_f_c_pix_put(t_datar *data, int i)
{
	int	y;

	y = 0;
	while (y < WINDOW_HEIGHT / 2)
	{
		ft_img_pix_put(&data->img, i, y, data->c);
		y++;
	}
	y = WINDOW_HEIGHT / 2;
	while (y < WINDOW_HEIGHT)
	{
		ft_img_pix_put(&data->img, i, y, data->f);
		y++;
	}	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:06:08 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/07/30 12:06:11 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

void	ft_cast_ray_init(t_datar *data, t_cast *ray, float ray_angle)
{
	ray->is_ray_facing_down = (ray_angle > 0 && ray_angle < MY_PI);
	ray->is_ray_facing_up = !ray->is_ray_facing_down;
	ray->is_ray_facing_right = (ray_angle < 0.5 * MY_PI
			|| ray_angle > 1.5 * MY_PI);
	ray->is_ray_facing_left = !ray->is_ray_facing_right;
	ray->found_horz_wall_hit = 0;
	ray->horzwall_hit_x = 0;
	ray->horzwall_hit_y = 0;
	ray->horz_wall_content = 0;
	ray->y_intercept = floor(data->player.y / TILE_SIZE) * TILE_SIZE;
}

void	ft_horz_touch(t_datar *data, t_cast *ray)
{
	while (ray->next_horz_touch_x >= 0 && ray->next_horz_touch_x
		<= data->sizeline * TILE_SIZE && ray->next_horz_touch_y
		>= 0 && ray->next_horz_touch_y <= data->nblines * TILE_SIZE)
	{
		ray->x_to_check = ray->next_horz_touch_x;
		if (ray->is_ray_facing_up)
			ray->y_to_check = ray->next_horz_touch_y - 1;
		else
			ray->y_to_check = ray->next_horz_touch_y;
		if (ft_map_has_wall_at(data, ray->x_to_check, ray->y_to_check))
		{
			ray->horzwall_hit_x = ray->next_horz_touch_x;
			ray->horzwall_hit_y = ray->next_horz_touch_y;
			ray->horz_wall_content = data->map[(int)floor(ray->y_to_check
					/ TILE_SIZE)][(int)floor(ray->x_to_check / TILE_SIZE)];
			ray->found_horz_wall_hit = 1;
			break ;
		}
		else
		{
			ray->next_horz_touch_x += ray->x_step;
			ray->next_horz_touch_y += ray->y_step;
		}
	}
}

void	ft_vert_touch_init(t_datar *data, t_cast *ray, float ray_angle)
{
	ray->found_vert_wall_hit = 0;
	ray->vert_wall_hit_x = 0;
	ray->vert_wall_hit_y = 0;
	ray->vert_wall_content = 0;
	ray->x_intercept = floor(data->player.x / TILE_SIZE) * TILE_SIZE;
	if (ray->is_ray_facing_right)
		ray->x_intercept += TILE_SIZE;
	ray->y_intercept = data->player.y + (ray->x_intercept - data->player.x)
		* tan(ray_angle);
	ray->x_step = TILE_SIZE;
	if (ray->is_ray_facing_left)
		ray->x_step *= -1;
	ray->y_step = TILE_SIZE * tan(ray_angle);
	if (ray->is_ray_facing_up && ray->y_step > 0)
		ray->y_step *= -1;
	if (ray->is_ray_facing_down && ray->y_step < 0)
		ray->y_step *= -1;
	ray->next_vert_touch_x = ray->x_intercept;
	ray->next_vert_touch_y = ray->y_intercept;
}

void	ft_vert_touch(t_datar *data, t_cast *ray, float ray_angle)
{
	ft_vert_touch_init(data, ray, ray_angle);
	while (ray->next_vert_touch_x >= 0 && ray->next_vert_touch_x
		<= data->sizeline * TILE_SIZE && ray->next_vert_touch_y
		>= 0 && ray->next_vert_touch_y <= data->nblines * TILE_SIZE)
	{
		if (ray->is_ray_facing_left)
			ray->x_to_check = ray->next_vert_touch_x - 1;
		else
			ray->x_to_check = ray->next_vert_touch_x;
		ray->y_to_check = ray->next_vert_touch_y;
		if (ft_map_has_wall_at(data, ray->x_to_check, ray->y_to_check))
		{
			ray->vert_wall_hit_x = ray->next_vert_touch_x;
			ray->vert_wall_hit_y = ray->next_vert_touch_y;
			ray->vert_wall_content = data->map[(int)floor(ray->y_to_check
					/ TILE_SIZE)][(int)floor(ray->x_to_check / TILE_SIZE)];
			ray->found_vert_wall_hit = 1;
			break ;
		}
		else
		{
			ray->next_vert_touch_x += ray->x_step;
			ray->next_vert_touch_y += ray->y_step;
		}
	}
}

void	ft_data_rays(t_datar *data, t_cast *ray, float ray_angle, int strip_id)
{
	if (ray->vert_hit_dist < ray->horz_hit_dist)
	{
		data->rays[strip_id].distance = ray->vert_hit_dist;
		data->rays[strip_id].wall_hit_x = ray->vert_wall_hit_x;
		data->rays[strip_id].wall_hit_y = ray->vert_wall_hit_y;
		data->rays[strip_id].wall_hit_content = ray->vert_wall_content;
		data->rays[strip_id].was_hit_vert = 1;
		data->rays[strip_id].ray_angle = ray_angle;
	}
	else
	{
		data->rays[strip_id].distance = ray->horz_hit_dist;
		data->rays[strip_id].wall_hit_x = ray->horzwall_hit_x;
		data->rays[strip_id].wall_hit_y = ray->horzwall_hit_y;
		data->rays[strip_id].wall_hit_content = ray->horz_wall_content;
		data->rays[strip_id].was_hit_vert = 0;
		data->rays[strip_id].ray_angle = ray_angle;
	}
	data->rays[strip_id].is_ray_facing_down = ray->is_ray_facing_down;
	data->rays[strip_id].is_ray_facing_up = ray->is_ray_facing_up;
	data->rays[strip_id].is_ray_facing_left = ray->is_ray_facing_left;
	data->rays[strip_id].is_ray_facing_right = ray->is_ray_facing_right;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_ray_utils_next.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 17:19:34 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/07/30 17:19:36 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/cub3d.h"

void	ft_cast_ray_init_next(t_datar *data, t_cast *ray, float ray_angle)
{
	if (ray->is_ray_facing_down)
		ray->y_intercept += TILE_SIZE;
	else
		ray->y_intercept += 0;
	ray->x_intercept = data->player.x + (ray->y_intercept - data->player.y)
		/ tan(ray_angle);
	ray->y_step = TILE_SIZE;
	if (ray->is_ray_facing_up)
		ray->y_step *= -1;
	else
		ray->y_step *= 1;
	ray->x_step = TILE_SIZE / tan(ray_angle);
	if (ray->is_ray_facing_left && ray->x_step > 0)
		ray->x_step *= -1;
	else
		ray->x_step *= 1;
	if (ray->is_ray_facing_right && ray->x_step < 0)
		ray->x_step *= -1;
	else
		ray->x_step *= 1;
	ray->next_horz_touch_x = ray->x_intercept;
	ray->next_horz_touch_y = ray->y_intercept;
}

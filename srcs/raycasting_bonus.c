/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:22:16 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/22 16:22:17 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_move_player(t_datar *data, float delta_time)
{
	float	move_step;
	float	move_side;
	float	new_player_x;
	float	new_player_y;

	move_step = 0;
	move_side = 0;
	new_player_x = 0;
	new_player_y = 0;
	data->player.rotation_angle += (data->player.turn_direction
			* data->player.turn_speed * delta_time);
	ft_normalize_angle(&data->player.rotation_angle);
	move_step = data->player.walk_direction * data->player.walk_speed
		* delta_time;
	move_side = data->player.walk_side * data->player.walk_speed * delta_time;
	new_player_x = data->player.x + cos(data->player.rotation_angle) * move_step
		+ (cos(data->player.rotation_angle - (MY_PI / 2)) * move_side);
	new_player_y = data->player.y + sin(data->player.rotation_angle) * move_step
		+ (sin(data->player.rotation_angle - (MY_PI / 2)) * move_side);
	if (!ft_map_has_wall_at(data, new_player_x, new_player_y)
		&& !ft_glitch(data))
	{
		data->player.x = new_player_x;
		data->player.y = new_player_y;
	}
}

void	ft_update(t_datar *data)
{
	float	delta_time;

	delta_time = FPS / 10;
	ft_move_player(data, delta_time);
	ft_cast_rays(data);
}

int	ft_render(t_datar *data)
{
	if (data->win_ptr == 0)
		return (0);
	ft_render_background(data, 0X424242);
	ft_render_wall(data);
	ft_render_map(data);
	ft_render_rays(data);
	ft_render_player(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img.mlx_img, 0, 0);
	if (data->win_ptr == 0)
		return (0);
	else
		ft_update(data);
	return (0);
}

int	ft_mlx(t_datar *data)
{
	ft_verify_errors(data);
	ft_init(data);
	ft_setup(data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, KeyRelease, KeyReleaseMask,
		&ft_handle_keyrelease, data);
	mlx_hook(data->win_ptr, DestroyNotify, LeaveWindowMask,
		&ft_handle_destroynotify, data);
	mlx_loop_hook(data->mlx_ptr, &ft_render, data);
	mlx_loop(data->mlx_ptr);
	return (0);
}

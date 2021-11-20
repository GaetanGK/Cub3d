/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:52:04 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/09 13:52:07 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_rays_init(t_datar *data)
{
	int	i;

	i = 0;
	while (i < NUM_RAYS)
	{
		data->rays[i].ray_angle = 0;
		data->rays[i].wall_hit_x = 0;
		data->rays[i].wall_hit_y = 0;
		data->rays[i].distance = 0;
		data->rays[i].was_hit_vert = 0;
		data->rays[i].is_ray_facing_up = 0;
		data->rays[i].is_ray_facing_down = 0;
		data->rays[i].is_ray_facing_left = 0;
		data->rays[i].is_ray_facing_right = 0;
		data->rays[i].wall_hit_content = 0;
		i++;
	}
}

int	ft_init(t_datar *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		ft_error(data, "Mlx init impossible\n");
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT,
			"Cub3D");
	if (data->win_ptr == NULL)
	{
		free(data->win_ptr);
		return (0);
	}
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH,
			WINDOW_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	ft_rays_init(data);
	return (1);
}

void	ft_get_texture_adress(t_datar *data)
{
	data->texture[0].addr = mlx_get_data_addr(data->texture[0].mlx_img,
			&data->texture[0].bpp, &data->texture[0].line_len,
			&data->texture[0].endian);
	data->texture[1].addr = mlx_get_data_addr(data->texture[1].mlx_img,
			&data->texture[1].bpp, &data->texture[1].line_len,
			&data->texture[1].endian);
	data->texture[2].addr = mlx_get_data_addr(data->texture[2].mlx_img,
			&data->texture[2].bpp, &data->texture[2].line_len,
			&data->texture[2].endian);
	data->texture[3].addr = mlx_get_data_addr(data->texture[3].mlx_img,
			&data->texture[3].bpp, &data->texture[3].line_len,
			&data->texture[3].endian);
}

void	ft_get_texture(t_datar *data)
{
	data->texture[0].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->ea,
			&(data->texture[0].width), &(data->texture[0].height));
	if (data->texture[0].mlx_img == NULL)
		ft_error(data, "Texture WE\n");
	data->texture[1].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->we,
			&(data->texture[1].width), &(data->texture[1].height));
	if (data->texture[1].mlx_img == NULL)
		ft_error(data, "Texture EA\n");
	data->texture[2].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->no,
			&(data->texture[2].width), &(data->texture[2].height));
	if (data->texture[2].mlx_img == NULL)
		ft_error(data, "Texture SO\n");
	data->texture[3].mlx_img = mlx_xpm_file_to_image (data->mlx_ptr, data->so,
			&(data->texture[3].width), &(data->texture[3].height));
	if (data->texture[3].mlx_img == NULL)
		ft_error(data, "Texture NO\n");
}

void	ft_setup(t_datar *data)
{
	data->player.x = data->dy * TILE_SIZE + 32;
	data->player.y = data->dx * TILE_SIZE + 32;
	data->player.width = 1;
	data->player.height = 1;
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.walk_side = 0;
	if (data->depart == 'N')
		data->player.rotation_angle = (3 * MY_PI) / 2;
	else if (data->depart == 'S')
		data->player.rotation_angle = MY_PI / 2;
	else if (data->depart == 'E')
		data->player.rotation_angle = MY_PI;
	else if (data->depart == 'W')
		data->player.rotation_angle = 0;
	data->player.walk_speed = 1;
	data->player.turn_speed = 0.5 * (MY_PI / 180);
	ft_get_texture(data);
	ft_get_texture_adress(data);
}

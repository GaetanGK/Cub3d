/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_key.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 17:08:08 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/09 17:08:09 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_handle_keypress(int keysym, t_datar *data)
{
	if (keysym == XK_Escape)
		ft_error(data, "Bye Bye !\n");
	if (keysym == XK_w || keysym == XK_W)
		data->player.walk_direction = +1;
	else if (keysym == XK_z || keysym == XK_Z)
		data->player.walk_direction = +1;
	else if (keysym == XK_s || keysym == XK_S)
		data->player.walk_direction = -1;
	else if (keysym == XK_Right)
		data->player.turn_direction = +1;
	else if (keysym == XK_Left)
		data->player.turn_direction = -1;
	else if (keysym == XK_d || keysym == XK_D)
		data->player.walk_side = -1;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_q
		|| keysym == XK_Q)
		data->player.walk_side = +1;
	return (0);
}

int	ft_handle_keyrelease(int keysym, t_datar *data)
{
	if (keysym == XK_w || keysym == XK_z || keysym == XK_W
		|| keysym == XK_Z)
		data->player.walk_direction = 0;
	else if (keysym == XK_s || keysym == XK_S)
		data->player.walk_direction = 0;
	else if (keysym == XK_Right)
		data->player.turn_direction = 0;
	else if (keysym == XK_Left)
		data->player.turn_direction = 0;
	else if (keysym == XK_d || keysym == XK_D)
		data->player.walk_side = 0;
	else if (keysym == XK_a || keysym == XK_A || keysym == XK_q
		|| keysym == XK_Q)
		data->player.walk_side = 0;
	return (0);
}

int	ft_handle_destroynotify(t_datar *data)
{
	ft_error(data, "Bye Bye !\n");
	return (0);
}

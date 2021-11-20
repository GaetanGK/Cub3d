/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 14:42:52 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/22 14:42:53 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_verify_errors(t_datar *recup)
{
	if (ft_murs(recup) == 1)
		ft_error(recup, "Map non entouree de 1\n");
	if (recup->depart == 'x')
		ft_error(recup, "Pas de joueur\n");
	if (recup->indicateur2 != 6)
		ft_error(recup, "Mauvaises donnees F ou C\n");
	if (recup->multijoueurs == 1)
		ft_error(recup, "Plus d'un joueur\n");
	if (recup->lignevide == 1)
		ft_error(recup, "Ligne vide dans la map\n");
	if (recup->wrongcharmap == 2)
		ft_error(recup, "Caractere incorrect dans la map\n");
}

void	ft_error(t_datar *recup, char *str)
{
	int	i;

	i = -1;
	recup->indicateur3 = 1;
	if (str[0] != 'B')
		write(1, "Error\n", 6);
	write(1, str, ft_strlen(str));
	if (recup->no)
		free(recup->no);
	if (recup->so)
		free(recup->so);
	if (recup->we)
		free(recup->we);
	if (recup->ea)
		free(recup->ea);
	if (recup->map)
	{
		while (++i < recup->nblines)
			free(recup->map[i]);
	}
	if (recup->map)
		free(recup->map);
	ft_exit(recup);
}

int	ft_exit(t_datar *recup)
{
	if (recup->indicateur3 == 0)
		ft_error(recup, "Exit");
	if (recup->img.mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->img.mlx_img);
	if (recup->texture[0].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[0].mlx_img);
	if (recup->texture[1].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[1].mlx_img);
	if (recup->texture[2].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[2].mlx_img);
	if (recup->texture[3].mlx_img)
		mlx_destroy_image(recup->mlx_ptr, recup->texture[3].mlx_img);
	if (recup->win_ptr)
	{
		mlx_destroy_window(recup->mlx_ptr, recup->win_ptr);
		mlx_destroy_display(recup->mlx_ptr);
		free(recup->mlx_ptr);
	}
	exit(0);
}

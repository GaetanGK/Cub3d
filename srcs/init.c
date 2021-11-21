/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:57:59 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/22 13:58:00 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	ft_init_more(t_datar *recup)
{
	recup->depart = 'x';
	recup->indicateur2 = 0;
	recup->indicateur3 = 0;
	recup->img.mlx_img = NULL;
	recup->texture[0].mlx_img = NULL;
	recup->texture[1].mlx_img = NULL;
	recup->texture[2].mlx_img = NULL;
	recup->texture[3].mlx_img = NULL;
	recup->win_ptr = NULL;
}

int	ft_nb_virgule(const char *str)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] == ',')
			j++;
	}
	return (j);
}

void	ft_atoi3_check(const char *str, t_datar *recup)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] != ',')
		i++;
	if (str[i] == ',')
		j = 1;
	i++;
	while (str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while ((str[i] < '0' || str[i] > '9') && str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j != 2)
		recup->erreur = 2;
	if (ft_nb_virgule(str) != 2)
		recup->erreur = 2;
}

int	ft_lignevide(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\0'
			&& str[i] != '\n' && str[i] != '\r' && str[i] != '\v'
			&& str[i] != '\f')
			return (1);
		i++;
	}
	return (0);
}

int	ft_map_dir_rony_check(char *fichier, t_datar *recup)
{
	int	fd;

	fd = open(fichier, O_DIRECTORY);
	if (fd != -1)
		ft_error(recup, "Invalide : is a directory\n");
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		ft_error(recup, "Fichier .map invalide\n");
	return (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 13:38:49 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/22 13:38:51 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_parsing_map(char *fichier, t_datar *recup)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = open(fichier, O_RDONLY);
	recup->map = malloc(sizeof(int *) * recup->nblines);
	if (recup->map == NULL)
		return (0);
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, recup);
		if (recup->insidemap == 1 && ft_lignevide(str) == 0
			&& recup->count < recup->nblines)
			recup->lignevide = 1;
		recup->insidemap = ft_is_map(str, recup);
		ft_map_copy(recup, str);
		free(str);
	}
	close(fd);
	ft_mlx(recup);
	return (0);
}

void	ft_parsing(char *fichier, t_datar *recup)
{
	int			fd;
	int			ret;
	char		*str;

	ret = 1;
	str = NULL;
	fd = ft_map_dir_rony_check(fichier, recup);
	recup->erreur = 0;
	while (ret != 0)
	{
		ret = get_next_line(fd, &str, recup);
		if (recup->erreur == 2)
			ft_error(recup, "Le parsing detecte une erreur\n");
		ft_color_resolution(&str, recup);
		ft_texture(str, recup);
		ft_map(str, recup);
		free(str);
	}
	close(fd);
	if (recup->sizeline == 0 || recup->nblines == 0)
		ft_error(recup, "Map absente\n");
	ft_parsing_map(fichier, recup);
}

int	ft_cub(char *str, t_datar *recup)
{
	int			i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(recup, "Nom de la map invalide\n");
			return (0);
		}
	}
	if (str[i + 4] != '\0')
		ft_error(recup, "Nom de la map invalide\n");
	else if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, recup);
	else
		ft_error(recup, "Nom de la map invalide\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_datar	recup;

	ft_initialisation(&recup);
	if (argc == 2)
		ft_cub(argv[1], &recup);
	else
		write(1, "Error\nArguments invalides\n", 26);
}

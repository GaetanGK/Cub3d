/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_color_resolution_texture.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Gkatounk <gkatounk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 15:03:59 by Gkatounk          #+#    #+#             */
/*   Updated: 2021/06/22 15:04:01 by Gkatounk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_atoi4(const char *str, t_datar *recup)
{
	int		verify;
	int		j;

	if (str[1] != ' ')
		recup->erreur = 2;
	ft_atoi3_check(str, recup);
	while (ft_test_str2(str[recup->i]) == 1)
	{
		recup->i++;
		j = 0;
		verify = 0;
		if (str[recup->i] >= '0' && str[recup->i] <= '9')
			recup->indicateur2++;
		while (str[recup->i] >= '0' && str[recup->i] <= '9')
		{
			verify = (verify * 10) + str[recup->i] - 48;
			recup->i++;
			j++;
		}
		if (verify > 255 || verify < 0)
			recup->erreur = 2;
		if (ft_test_str(str[recup->i - 1]) == 1)
			recup->sum = (recup->sum << 8) + verify;
	}
	return (recup->sum);
}

int	ft_texture_null(t_datar *recup, char **texture)
{
	recup->count2 = 0;
	if (*texture != NULL)
	{
		recup->erreur = 2;
		return (0);
	}
	return (1);
}

int	ft_path_texture(char *str, char **texture, t_datar *recup, int j)
{
	recup->count2 = 0;
	if (ft_texture_null(recup, texture) == 0)
		return (0);
	if (ft_charinstr(str, '.') == 0 || ft_charinstr(str, '/') == 0
		|| ft_strlen2(str) <= 2)
		recup->erreur = 2;
	while (str[j] != '.')
	{
		if (str[j] != ' ' && str[j] != '.')
			recup->erreur = 2;
		j++;
	}
	*texture = (char *)(malloc(sizeof(char) * (ft_strlen2(str) + 1)));
	if (!(*texture))
		recup->erreur = 2;
	while (str[j] != '\0')
	{
		(*texture)[recup->count2] = str[j];
		recup->count2++;
		j++;
	}
	(*texture)[recup->count2] = '\0';
	return (0);
}

void	ft_texture(char *str, t_datar *recup)
{
	int			i;
	static int	j = 0;

	i = 0;
	if (str[i] == 'S' && str[i + 1] == 'O')
		ft_path_texture(str, &recup->no, recup, 2);
	else if (str[i] == 'N' && str[i + 1] == 'O')
		ft_path_texture(str, &recup->so, recup, 2);
	else if (str[i] == 'E' && str[i + 1] == 'A')
		ft_path_texture(str, &recup->we, recup, 2);
	else if (str[i] == 'W' && str[i + 1] == 'E')
		ft_path_texture(str, &recup->ea, recup, 2);
	else if (str[0] != 'N' && str[0] != 'S' && str[0] != 'W' && str[0] != 'E'
		&& str[0] != 'F' && str[0] != 'C'
		&& str[0] > 65 && str[0] < 122)
		recup->erreur = 2;
	j++;
}

void	ft_color_resolution(char **str, t_datar *recup)
{
	int			i;

	i = 0;
	recup->i = 1;
	if (recup->sizeline > 0 && (recup->no == NULL || recup->so == NULL
			|| recup->we == NULL || recup->ea == NULL))
		recup->erreur = 2;
	if (*str[i] == 'C')
		recup->c = ft_atoi4(*str, recup);
	else if (*str[i] == 'F')
		recup->f = ft_atoi4(*str, recup);
}

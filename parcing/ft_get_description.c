/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_description.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:16:13 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 01:50:57 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	place_data_2(t_data *data, int i, int j, char c)
{
	data->player->i_p = i;
	data->player->j_p = j;
	data->player->c_p = c;
}

void	place_data(t_data *data, int i, int j)
{
	char	c;

	c = data->map->map2[i][j];
	if (c == '0' || c == '1' || c == ' ')
		return ;
	else if (c == 'N' && (!data->player->c_p))
		place_data_2(data, i, j, 'N');
	else if (c == 'S' && (!data->player->c_p))
		place_data_2(data, i, j, 'S');
	else if (c == 'E' && (!data->player->c_p))
		place_data_2(data, i, j, 'E');
	else if (c == 'W' && (!data->player->c_p))
		place_data_2(data, i, j, 'W');
	else
		return (ft_print_fd(2, "duplicate ressources \n"), exit(51));
}

void	check_is_side(t_data *data)
{
	char	**str;
	int		i;
	int		j;

	str = data->map->map2;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] != '1' && str[i][j] != ' ' && is_in_wrong_place(i, j,
					str))
				return ((void)printf("---%c---%d---%d\n", str[i][j], i, j),
					ft_print_fd(2, "open map\n"), exit(80));
			j++;
		}
		i++;
	}
}

void	count_get_ressources(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map2[i])
	{
		j = 0;
		while (data->map->map2[i][j])
		{
			if (ft_strchr("01NSEW ", data->map->map2[i][j]))
				place_data(data, i, j);
			else
				return (ft_print_fd(2, "wrong data on the matrix\n"), exit(68));
			j++;
		}
		i++;
	}
	if (!(data->player->c_p))
		return (ft_print_fd(2, "no starting player point\n"), exit(84));
}

void	ft_get_description(t_data *data, char *str)
{
	fill_tabs(data, str);
	fill_description(data);
	count_get_ressources(data);
	check_is_side(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hundle_clr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:36:49 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 02:05:56 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	get_len_wei_map(t_mapp *map, int i)
{
	int	j;

	while (map->map1[i])
	{
		if (map->longer_line < ft_strlen(map->map1[i]))
			map->longer_line = ft_strlen(map->map1[i]);
		map->line_nbr++;
		i++;
	}
	if (map->line_nbr <= 2 || map->longer_line <= 2)
		return (ft_print_fd(2, "error\n"), exit(19));
	map->map2 = (char **)malloc(sizeof(char *) * (map->line_nbr + 1));
	if (!map->map2)
		return (ft_print_fd(2, "error\n"), exit(19));
	j = 0;
	while (j <= map->line_nbr)
	{
		map->map2[j] = (char *)malloc(sizeof(char) * (map->longer_line + 1));
		if (!map->map2[j])
			return (ft_print_fd(2, "error\n"), exit(19));
		j++;
	}
}

int	fill_second_map(t_mapp *map, int i)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	while (map->map1[i])
	{
		k = 0;
		while (map->map1[i][k])
		{
			map->map2[j][k] = map->map1[i][k];
			k++;
		}
		while (k < map->longer_line)
		{
			map->map2[j][k] = ' ';
			k++;
		}
		map->map2[j][k] = '\0';
		i++;
		j++;
	}
	map->map2[j] = 0;
	/*j = 0;
	while (map->map2[j])
	{
		printf("%s\n", map->map2[j]);
		j++;
	}*/
	return (i);
}

int	go_creat_map(t_data *data, int i)
{
	t_mapp	*mapa;

	data->map->into_map = 1;
	mapa = data->map;
	get_len_wei_map(mapa, i);
	return (fill_second_map(mapa, i) - 1);
}

unsigned long	counting(char **str)
{
	int	count;
	int	tab[3];

	count = 0;
	while (str[count])
	{
		if (count > 2)
			return (ft_print_fd(2, "pb\n"), exit(30), 1337);
		if (!ft_is_alpha(str[count]))
			return (ft_print_fd(2, "pb\n"), exit(31), 1337);
		tab[count] = ft_atoi(str[count]);
		if (tab[count] < 0 || tab[count] > 255)
			return (ft_print_fd(2, "pb\n"), exit(32), 1337);
		count++;
	}
	if (count != 3)
		return (ft_print_fd(2, "wrong in the nbr of data in rgb vars\n"),
			exit(24), 1337);
	return (((tab[0] << 16) | (tab[1] << 8) | tab[2]));
}

unsigned long	get_and_handle_clr(char *str, int j)
{
	char	**clrs;

	if (str[j] != ' ')
		return (ft_print_fd(2, "error\n"), exit(16), 16);
	clrs = ft_split(str + j, ',');
	if (!clrs)
		return (exit(99), 1337);
	return (counting(clrs));
}

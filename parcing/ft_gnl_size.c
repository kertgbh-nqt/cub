/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 21:36:10 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 01:15:24 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int	ft_gnl_size(char *str)
{
	int		fd;
	int		i;
	char	*buff;

	i = 0;
	fd = open(str, O_RDONLY);
	while (1)
	{
		buff = get_next_line(fd);
		if (buff == NULL)
			break ;
		i++;
		free(buff);
	}
	close(fd);
	return (i);
}

void	fill_tabs(t_data *data, char *str)
{
	int		fd;
	int		i;
	t_mapp	*mapa;

	i = 0;
	mapa = data->map;
	mapa->biglen = ft_gnl_size(str);
	mapa->map1 = (char **)malloc(sizeof(char *) * (mapa->biglen + 1));
	if (!mapa->map1)
		return (ft_print_fd(2, "cant allocat for map1\n"), exit(6));
	fd = open(str, O_RDONLY);
	while (1)
	{
		mapa->map1[i] = get_next_line(fd);
		mapa->map1[i] = ft_strtrim(mapa->map1[i], "\n");
		if (mapa->map1[i] == NULL)
			break ;
		i++;
	}
	mapa->map1[i] = NULL;
	close(fd);
}

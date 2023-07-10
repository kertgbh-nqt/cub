/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_description.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 01:19:52 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/10 02:08:00 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	is_the_texture_valid(char *str)
{
	int		len;
	char	buff[1];
	int		fd;

	len = ft_strlen(str) - 1;
	if (len <= 4)
		return (ft_print_fd(2, str), ft_print_fd(2, " texture too short\n"),
			exit(21));
	if (str[len] != 'm' || str[len - 1] != 'p' || str[len - 2] != 'x'
		|| str[len - 3] != '.')
		return (ft_print_fd(2, str), ft_print_fd(2, ": invalide textute \n"),
			exit(20));
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_print_fd(2, "can't open/find your .xpm map\n"),
			(void)close(fd), exit(25));
	if (read(fd, buff, 1) == -1)
		return (ft_print_fd(2, "your file xpm is a directory ? \n"),
			(void)close(fd), exit(26));
	close(fd);
}

char	*get_and_check_texture(char *str, int j)
{
	int		start;
	char	*ret;

	if (str[j] == '\0')
		return (ft_print_fd(2, "empty var"), (void)write(2, &str[j - 2], 1),
			(void)write(2, &str[j - 1], 1), (void)write(2, "\n", 1), exit(18),
			NULL);
	while (str[j] && ((str[j] == ' ') || (str[j] == '\t')))
		j++;
	if (str[j] != 0)
		start = j;
	while (str[j] && (str[j] != ' ' && str[j] != '\t'))
		j++;
	if (str[j])
		return (ft_print_fd(2, "invalid var\n"), exit(19), NULL);
	ret = ft_substr(str, start, j - start + 1);
	is_the_texture_valid(ret);
	return (ret);
}

int	ft_place_data(t_data *data, int i, int j)
{
	data->str = data->map->map1[i];
	if (data->str[j] == '\0')
		return (i);
	else if (data->str[j] == 'S' && data->str[j + 1] == 'O'
		&& data->str[j + 2] == ' ' && !(data->map->so_str))
		data->map->so_str = get_and_check_texture(data->str, j + 2);
	else if (data->str[j] == 'W' && data->str[j + 1] == 'E'
		&& data->str[j + 2] == ' ' && !(data->map->we_str))
		data->map->we_str = get_and_check_texture(data->str, j + 2);
	else if (data->str[j] == 'E' && data->str[j + 1] == 'A'
		&& data->str[j + 2] == ' ' && !(data->map->ea_str))
		data->map->ea_str = get_and_check_texture(data->str, j + 2);
	else if (data->str[j] == 'N' && data->str[j + 1] == 'O'
		&& data->str[j + 2] == ' ' && !(data->map->no_str))
		data->map->no_str = get_and_check_texture(data->str, j + 2);
	else if (norm(data->str, j, 'C') && (!data->map->c_rgb))
		data->map->c_rgb = get_and_handle_clr(data->str, j + 1);
	else if (norm(data->str, j, 'F') && (!data->map->f_rgb))
		data->map->f_rgb = get_and_handle_clr(data->str, j + 1);
	else if (data->str[j] == '1' || data->str[j] == '0')
		return (go_creat_map(data, i));
	else
		return (ft_print_fd(2, "duplcate/invalide input\n"), exit(17), i);
	return (i);
}

void	fill_description(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map->map1[i])
	{
		j = 0;
		while (ft_is_space(data->map->map1[i][j]))
			j++;
		if (ft_strchr("SWENFC01", data->map->map1[i][j]))
			i = ft_place_data(data, i, j);
		else if (data->map->map1[i][j] == 0)
			continue ;
		else
			return (ft_print_fd(2, "tatcheki had errorn"), exit(16));
		i++;
	}
	if (data->map->into_map == 0)
		return (ft_print_fd(2, "no map my friend\n"), exit(94));
	if (!data->map->no_str || !data->map->ea_str || !data->map->we_str
		|| !data->map->so_str)
		return (ft_print_fd(2, "not enough ressources\n"), exit(93));
}

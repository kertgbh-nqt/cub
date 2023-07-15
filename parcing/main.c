/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:23:30 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/15 04:49:41 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void	init_map(t_mapp *map)
{
	map->so_str = NULL;
	map->we_str = NULL;
	map->no_str = NULL;
	map->ea_str = NULL;
	map->c_rgb = 0;
	map->f_rgb = 0;
	map->into_map = 0;
	map->longer_line = 0;
	map->line_nbr = 0;
}

void	init_player(t_player *player)
{
	player->i_p = -1;
	player->j_p = -1;
	player->c_p = '\0'; //itijah
	player->radius = 10;
	player->TurnDirection = 0;
	player->WalkDirection = 0;
	player->RotationAngle = M_PI / 2;
	player->MoveSpeed = 2.0;
	player->RotationSpeed = 2 * (M_PI / 180); 
}

//void	init_libx(t_lib *libix)
//{
//
//}

void	init_struct(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!(*data))
		printf("error");
	(*data)->map = malloc(sizeof(t_mapp));
	if (!(*data)->map)
		printf("error");
	(*data)->player = malloc(sizeof(t_player));
	init_map((*data)->map);
	init_player((*data)->player);
	(*data)->libix = malloc(sizeof(t_lib));
	//init_libx((*data)->libix);
}

void	part_parcing(t_data *data, char *str)
{
	ft_check_name(str);
	ft_get_description(data, str);	
}

int	main(int ac, char **av)
{
	if (ac == 2)
	{
		t_data	*data;

		data = NULL;
		init_struct(&data);
		part_parcing(data, av[1]);
		part_graphic(data);
	}
	else
		return (ft_print_fd(2, "2 much args\n"), 2);
	return (0);
}

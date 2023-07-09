/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:23:30 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 18:12:27 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

void    init_map(t_mapp *map)
{
    map->SO_str = NULL;
    map->WE_str = NULL;
    map->NO_str = NULL;
    map->EA_str = NULL;
    map->C_rgb = 0;
    map->F_rgb = 0;
    map->longer_line = 0;
    map->line_nbr = 0;
}

void    init_struct(t_data **data)
{
    *data = malloc(sizeof(t_data));
    if (!(*data))
        printf ("error");
    (*data)->map = malloc(sizeof(t_mapp));
     if (!(*data)->map)
        printf ("error");
   init_map((*data)->map);
   
}

int main(int ac, char **av)
{
    t_data *data;
    //more than one parametre go back
    if (ac == 2)
    {
       data = NULL;
        //need to initialise it with NULL
        init_struct(&data);
        //check name
        ft_check_name(av[1]);
        //while for content before map
        ft_get_description(data, av[1]);
        //resize map / srocked /check ressources
        //check if around are 1
    }
    else
        return (ft_print_fd(2, "2 much args\n"), 2);
    return (0);
}
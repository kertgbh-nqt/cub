/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 04:22:36 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/15 03:28:01 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

int ft_exit_key(void)
{
    return(exit(0), 0);
}
void    draw(t_data *data, int x,int y, int color)
{
    int i;
    int j;
    
    i = 0;
    while (i < 32)
    {
        j = 0;
        while (j < 32)
        {
            mlx_pixel_put(data->libix->mlx, data->libix->win, i + x, j + y, color);
            j++;
        } 
        i++;
    }
}

void    print_map(t_data *data)
{
    int x;
    int y;
    int color;
    
    y = 0;
    while (y < data->map->line_nbr)
    {
        x = 0;
        while(x < data->map->longer_line)
        {
            if (data->map->map2[y][x] == '1')
                color = 0x808080;
            else
                color = 0xA52A2A;
            draw(data, x * 32, y * 32, color);
            x++;
        }
        y++;
    }
}

void    part_graphic(t_data *data)
{
    data->libix->mlx =  mlx_init();
    printf ("%d--%d\n", data->map->longer_line, data->map->line_nbr);
    data->libix->win = mlx_new_window(data->libix->mlx, 32 * data->map->longer_line , 32 * data->map->line_nbr, "cub3d");
    print_map(data);
    mlx_hook(data->libix->win, 17, 0, ft_exit_key, data->libix);
   mlx_loop(data->libix->mlx);
}

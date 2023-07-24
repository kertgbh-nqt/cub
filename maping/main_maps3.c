// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_maps3.c                                       :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/19 21:38:28 by mel-garr          #+#    #+#             */
// /*   Updated: 2023/07/23 01:43:40 by mel-garr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cube3d.h"

// int     print_world(t_data *data);


// int f_out(void)
// {
//     exit(0);
//     return (0);
// }

// int keys(int key, t_data *data)
// {
//     float angle ;
//     angle = data->player->a_p * (M_PI / 180);
    
//     if (key == 53)
//         exit(0);
//     else if (key == 2)
//     {
//         P_I -= (M_S * cos(angle));
//        P_J -= (M_S * sin(angle));
//     }
//     else if (key == 0)
//     {
//         P_I += (M_S * cos(angle));
//         P_J += (M_S * sin(angle));
//     }
//     else if (key == 1)
//     {
//         P_I += (M_S * cos(angle + M_PI / 2));
//         P_J += (M_S * sin(angle + M_PI / 2));
//     }
//     else if (key == 13)
//     {
//         P_I -= (M_S * cos(angle + M_PI / 2));
//         P_J -= (M_S * sin(angle + M_PI / 2));
//     }
//     else if (key == 123)
//     {
//         data->player->a_p = fmod((data->player->a_p + data->player->RotationSpeed), 360);
//         if (data->player->a_p < 0)
//             data->player->a_p += 360;
//     }
//     else if (key == 124)
//     {
//         data->player->a_p = fmod((data->player->a_p - data->player->RotationSpeed), 360);
//         if (data->player->a_p < 0)
//             data->player->a_p += 360;
//     }
//     print_world(data);
//     return(0);
// }

// void    draw(int y, int x, t_data *data, int color)
// {
//     int i   ;
//     int j;

//     i = 0;
//     while (i < TILE_SIZE - 1)
//     {
//         j = 0;
//         while (j < TILE_SIZE - 1)
//         {
//             mlx_pixel_put(m_init, m_win, i + y, j + x, color);
//             j++;
//         }
//         i++;
//     }
// }

// void    print_line(t_data *data)
// {
//     float new_x;
//     float new_y;
//     float dst_x;
//     float dst_y;
//     float angle ;
//     angle = data->player->a_p * (M_PI / 90);
//     printf ("||%f||--||%f||\n", angle , data->player->a_p);
//     new_x = (P_I * TILE_SIZE) + (TILE_SIZE / 2);
//     new_y = (P_J * TILE_SIZE) + (TILE_SIZE / 2);
//     dst_x = new_x + (cos(angle) * 30) ;
//     dst_y = new_y + (sin(angle) * 30);
//     while((fabsf(dst_x - new_x) > 1) || (fabsf(dst_y - new_y) > 1))
//     {
//         mlx_pixel_put(m_init, m_win, new_y, new_x, BLUE);
//          new_x += (cos(angle)) * 1;
//          new_y += (sin(angle)) * 1;
//          printf ("||%f|| -- ||%f||--||%f||--||%f||\n", new_x, new_y, dst_x, dst_y);
//         // new_x += 3;
//         // new_y -= 3;
//     }
// }

// void    print_playa(t_data *data)
// {
//     float i;
//     float j;
//     float rad;
//     float di;
//     float dj;
//     float x;
//     float y;
    
//     x = (P_I * TILE_SIZE) + (TILE_SIZE / 2);
//     y = (P_J * TILE_SIZE) + (TILE_SIZE / 2);
//     rad = 5;
//     i =  x - rad;
//     while (i <= x + rad)
//     {
//         j = y - rad;
//         while (j < y + rad)
//         {
//             di = i - x;
//             dj = j - y;
//             if (di * di + dj * dj <= rad * rad)
//                 mlx_pixel_put(m_init, m_win,  j, i, BLUE);
//             j++;
//         }
//         i++;
//     }    
//     print_line(data);
// }

// int     print_world(t_data *data)
// {
//     int x;
//     int y;
//     int color;

//     x = 0;
//     while (x < Lnum)
//     {
//         y = 0;
//         while (y < LLine)
//         {
//             if (data->map->map2[x][y] == '1')
//                 color = GREY;
//             else
//                 color = RED;
//             draw(y * 32 , x * 32, data, color);
//             y++;

//         }
//         x++;
//     }
//     print_playa(data);
//     return (0);
// }

// void    part_graphic(t_data *data)
// {
//     m_init= mlx_init();
//     m_win = mlx_new_window(m_init, TILE_SIZE * LLine, TILE_SIZE * Lnum , "CUBE3D");
//     mlx_clear_window(m_init, m_win);
//     print_world(data);
//     //mlx_loop_hook(m_init, &print_world, data);
//     mlx_hook(m_win, 2, 0, keys, data);
//     mlx_hook(m_win, 17, 0, f_out, data);
//     mlx_loop(m_init);
// }

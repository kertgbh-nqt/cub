// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main_maps.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/14 04:22:36 by mel-garr          #+#    #+#             */
// /*   Updated: 2023/07/18 03:27:28 by mel-garr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cube3d.h"

// int ft_exit_key(void)
// {
//     return(exit(0), 0);
// }
// void    draw(t_data *data, int x,int y, int color)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while (i < 32)
//     {
//         j = 0;
//         while (j < 32)
//         {
//             mlx_pixel_put(data->libix->mlx, data->libix->win, i + x, j + y, color);
//             j++;
//         } 
//         i++;
//     }
// }

// void    print_map(t_data *data)
// {
//     int x;
//     int y;
//     int color;
    
//     y = 0;
//     while (y < data->map->line_nbr)
//     {
//         x = 0;
//         while(x < data->map->longer_line)
//         {
//             if (data->map->map2[y][x] == '1')
//                 color = 0x808080;
//             else
//                 color = 0xA52A2A;
//             draw(data, x * 32, y * 32, color);
//             x++;
//         }
//         y++;
//     }
// }

// void    draw_player(t_data *data)
// {
//     int i;
//     int j;
//     int x;
//     int y;
//     int di;
//     int dj;
//     float radius;
    
//     radius = data->player->radius;
//     radius = 6;
//     i = data->player->i_p * 32 +  16;
//     j = data->player->j_p * 32 + 16;
//     x = i - radius;
//     while(x <=  i + radius)
//     {
//         y = j - radius;
//         while (y <= j + radius)
//         {
//             di = x - i;
//             dj = y - j;
//             if (di * di + dj * dj <= radius * radius)
//                 mlx_pixel_put(data->libix->mlx, data->libix->win, y, x, 0x0000FF);
//             y++;
//         }
//         x++;     
//     }
// }


// /*void new_r(t_data *data)
// {
//     int i;
//     int j;
//     int bi;
//     int bj;
//     i = data->player->i_p;
//     j = data->player->j_p;
//     bi = data->player->walk_direction_y;
//     bj = data->player->walk_direction_x;
//     if (i < bj && j < bj)
//     {
//         bj +=  
//     }
// }*/
// // int y_new_r(t_data *data){}
// // int x_new_l(t_data *data){}
// // int y_new_l(t_data *data){}

// /*int ft_key(int key, t_data *data)
// {
//     //(void)data;
//     //if (key == 124)
//     //    new_r(data);
//     //else if (key == 123)
//     //    new_l(data);
//     if (key == 13)
//     {
//         data->map->map2[data->player->i_p][data->player->j_p] = '0';
//         data->map->map2[data->player->i_p + 1][data->player->j_p] = 'S';
//     }
//     else if (key == 1)
//         data->player->i_p -= 1;
//     else if (key == 2)
//         data->player->j_p += 1;
//     else if (key == 0)
//         data->player->j_p -= 1;
//     else if (key == 53)
//         exit(0);
    
//     return (printf ("%d---%d--\n", data->player->i_p, data->player->j_p));
// }*/

// //int    get_line_x_y(int *a, int *b, t_data *data)
// /*int     get_line_x_y(t_data *data)
// {
//     int ret;
    
//     ret = 0;
//     if (data->player->c_p == 'S')
//     {
//         // *a = (data->player->j_p * TILE_SIZE) + TILE_SIZE / 2;
//         // *b = (data->player->i_p * TILE_SIZE) + TILE_SIZE + TILE_SIZE / 2;
//         data->player = (data->player->j_p * TILE_SIZE) + TILE_SIZE / 2;
//         *b = (data->player->i_p * TILE_SIZE) + TILE_SIZE + TILE_SIZE / 2;
//         ret = 1;
//     }
//     else  if (data->player->c_p == 'N')
//     {
//         *a = (data->player->j_p * TILE_SIZE) + TILE_SIZE / 2;
//         *b = (data->player->i_p * TILE_SIZE) - TILE_SIZE + TILE_SIZE / 2;
//         ret = 0;
//     }
//     else  if (data->player->c_p == 'E')
//     {
//         *a = (data->player->j_p * TILE_SIZE) + TILE_SIZE + TILE_SIZE / 2;
//         *b = (data->player->i_p * TILE_SIZE) + TILE_SIZE / 2;
//         ret = 1;
//     }
//     else  if (data->player->c_p == 'W')
//     {
//         *a = (data->player->j_p * TILE_SIZE) - TILE_SIZE + TILE_SIZE / 2;
//         *b = (data->player->i_p * TILE_SIZE) + TILE_SIZE / 2;
//         ret = 0;
//     }
//     return (ret);
// }*/

// void    draw_line(t_data *data)
// {
//     //int new_x;
//    // int new_y;
//     int i;
//     int j;
//    //int signe;
//     i = (data->player->i_p * TILE_SIZE) + TILE_SIZE / 2;
//     j = (data->player->j_p * TILE_SIZE) + TILE_SIZE / 2;
//     //signe = get_line_x_y(&new_x , &new_y, data);
//     //signe = get_line_x_y(data);
//     while (1)
//     {
//         mlx_pixel_put(data->libix->mlx, data->libix->win, j, i, 0x0000FF);
//         if (j == data->player->walk_direction_x && i == data->player->walk_direction_y)
//             break;
//         if (j > data->player->walk_direction_x)
//             j += 1;
//         else if (j < data->player->walk_direction_x )
//             j -= 1;
//         if (i > data->player->walk_direction_y )
//             i -= 1;
//         else if (i < data->player->walk_direction_y )
//             i += 1;
//     }
// }

// /*void    drawW_line(t_data *data)
// {
//     int lin_x;
//     int lin_y;
//     int i;
//     int j;
//     int dx;
//     int dy;
//     int err;
//     int err2;
//     int signe_x;
//     int signe_y;

//     i = data->player->i_p * 32 + 16;
//     j = data->player->j_p * 32 + 16;
//     lin_x = i + cos(20 * data->player->RotationAngle) * 30;
//     lin_y = j + sin(20 * data->player->RotationAngle) * 30;
//     dx = abs(lin_x - i);
//     dy = abs(lin_y - j);
//     err = dx - dy;
//     if (lin_x > i)
//         signe_x = 1;
//     else
//         signe_x = -1;
//     if (lin_y > j)
//         signe_y = 1;
//     else
//         signe_y = -1;
//     dx = abs(lin_x - i);
//     dy = abs(lin_y - j);
//     while (1)
//     {
//         mlx_pixel_put(data->libix->mlx, data->libix->win, j, i, 0x0000FF);
//         if ((i == lin_x) && (j == lin_y))
//             break;
//         err2 = 2 * err;
//         if (err2 > -dy)
//         {
//             err -= dy;
//             i += signe_x;
//         }
//         if (err2 < dx)
//         {
//             err += dx;
//             j += signe_y;
//         }
//     }
    
// }*/

// int ft_key(int key, void *param)
// {
//     t_data *data;

//     data = param;
//     if (key == 1)
//     {
//         data->player->i_p += data->player->MoveSpeed * cos(data->player->RotationAngle);
//         data->player->j_p += data->player->MoveSpeed * sin(data->player->RotationAngle);
//     }
//     // else if (key == 13)
//     // else if (key == 0)
//     // else if (key == 2)
//     return (0);
// }

// void    part_graphic(t_data *data)
// {
//     data->libix->mlx =  mlx_init();
//     data->libix->win = mlx_new_window(data->libix->mlx, TILE_SIZE * data->map->longer_line , TILE_SIZE * data->map->line_nbr, "cub3d");
//         mlx_clear_window(data->libix->mlx, data->libix->win);
//         print_map(data);
//         draw_player(data);
//         draw_line(data);
//         mlx_key_hook(data->libix->win, ft_key, data);
//         //mlx_loop_hook(data->libix->mlx, ft_key, data);
//         //mlx_hook(data->libix->win, 17, 0, ft_exit_key, data->libix);
//         mlx_loop(data->libix->mlx);
// }

// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.map2.c                                        :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/07/18 03:19:25 by mel-garr          #+#    #+#             */
// /*   Updated: 2023/07/19 21:37:33 by mel-garr         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../includes/cube3d.h"
// void print_strock(t_data *data);
// void    draw_line(t_data *data);

// void    draw(t_data *data, int y, int x, int color)
// {
//     int i;
//     int j;
    
//     i = 0;
//     while (i < 32 + 1)
//     {
//         j = 0;
//         while (j < 32 + 1)
//         {
//             mlx_pixel_put(data->libix->mlx, data->libix->win, i + y, j + x, color);
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

//     x = 0;
//     while (x < data->map->line_nbr)
//     {
//         y = 0;
//         while(y < data->map->longer_line)
//         {
//             if (data->map->map2[x][y] == '1')
//                 color = 0x808080;
//             else
//                 color = 0xA52A2A;
//             draw(data, y * 32, x * 32, color);
//             y++;
//         }
//         x++;
//     }
// }
// int ft_exit_key(int key,t_data *data)
// {
//     (void)data;
//     printf ("%d\n", key);
//     if (key == 53)
//         exit(0);
//     return (2);
// }
// /*int ft_exi(int key)
// {
//     if (key == 53)
//         exit(5);
//         return(0);
// }*/
// void    print_player(t_data *data)
// {
//     int i;
//     int j;
//     int x;
//     int y;
//     int di;
//     int dj;

//     i = data->player->i_p * TILE_SIZE + TILE_SIZE / 2;
//     j = data->player->j_p * TILE_SIZE + TILE_SIZE / 2;
//     x = i - 6;
//     while (x <= i + 6)
//     {
//         y = j - 6;
//         while(y < j + 6)
//         {
//             di = x - i;
//             dj = y - j;
//             if (di * di + dj * dj <= 6 * 6)
//                 mlx_pixel_put(data->libix->mlx, data->libix->win, y, x, 0x0000FF);   
//             y++;
//         }
//         x++;
//     }
//    // draw_line(data);
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
//     rad = 6;
//     i =  x - rad;
//     while (i <= x + rad)
//     {
//         j = y - rad;
//         while (j < y + rad)
//         {
//             di = i - x;
//             dj = j - y;
//             if (di * di + dj * dj <= 6 * 6)
//                 mlx_pixel_put(m_init, m_win,  j, i, BLUE);
//             j++;
//         }
//         i++;
//     }
    
//     printf ("wsselt hna");
//     //print_line();
// }
// void    draw_line(t_data *data)
// {
//     int new_i;
//     int new_j;
//     int dst_i;
//     int dst_j;

//     data->player->RotationAngle = data->player->RotationAngle + data->player->TurnDirection ;
//     new_i = (data->player->i_p * 32) + (TILE_SIZE / 2);
//     new_j = (data->player->j_p * 32) + (TILE_SIZE / 2);
//     //dst_i = new_i +  (cos(data->player->RotationAngle) * 20) ;
//     //dst_j = new_j +  (sin(data->player->RotationAngle) * 20);
//     dst_i = new_i + 50;
//     dst_j = new_j + 10;

//     while (1)
//     {
//         mlx_pixel_put(data->libix->mlx, data->libix->win, new_j, new_i, 0x0000FF);
//         if((dst_i == new_i) || (dst_j == new_j))
//             break;
//         if  (new_i > dst_i)
//             new_i--;
//         else if (new_i < dst_i)
//             new_i++;
//         else if (new_j < dst_j)
//             new_j++;
//         else if (new_j > dst_j)
//             new_j++;
    
//     }
    
// }

// int    update(t_data *data)
// {
//     float move_step;
//     float move_rotation;
    
//     move_step = data->player->WalkDirection * data->player->MoveSpeed;
//     move_rotation = data->player->TurnDirection * data->player->RotationSpeed;
//     data->player->i_p += cos(data->player->RotationAngle) * move_step;
//     data->player->j_p += sin(data->player->RotationAngle) * move_step; 
    
//     //data->player->RotationAngle += data->player->TurnDirection * data->player->RotationSpeed;
    
//     print_map(data);
//     print_player(data);

//     return (0);
// }

// int pressed_key(int key, t_data *data)
// {
//     if (key == 13)
//         data->player->WalkDirection = 1;
//     else if (key == 1)
//         data->player->WalkDirection = -1;
//     else if (key == 2)
//         data->player->TurnDirection = 1;
//     else if (key == 0)
//         data->player->TurnDirection = -1;
//     update(data);
//     return (0);
// }

// int released_key(int key, t_data *data)
// {
//     if (key == 13 || key == 1)
//         data->player->WalkDirection = 0;
//     else if (key == 2 || key == 0)
//         data->player->TurnDirection = 0;
//     return (0);
// }

// /*void    draw_line(t_data *data)
// {
//   int new_i;
//   int new_j;

//     new_i = (data->player->i_p * 32) + (TILE_SIZE / 2);
//     new_j = (data->player->j_p * 32) + (TILE_SIZE / 2); 

//     while (1)
//     {
//         mlx_pixel_put(data->libix->mlx, data->libix->win, new_j, new_i, 0x0000FF);
//         if((data->player->walk_direction_y == new_i) && (data->player->walk_direction_x == new_j))
//             break;
//         if (new_i > data->player->walk_direction_y)
//             new_i--;
//         else if (new_i < data->player->walk_direction_y)
//             new_i++;
//         else if (new_j > data->player->walk_direction_x)
//             new_j--;
//         else if (new_j < data->player->walk_direction_x)
//             new_j++;

//       printf ("%d--%d--%d---%d\n", new_i, new_j, data->player->walk_direction_x, data->player->walk_direction_y);
//     }
    
// }*/


// void    part_graphic(t_data *data)
// {
//         data->libix->mlx =  mlx_init();
//         data->libix->win = mlx_new_window(data->libix->mlx, TILE_SIZE * data->map->longer_line , TILE_SIZE * data->map->line_nbr, "cub3d");
//         mlx_clear_window(data->libix->mlx, data->libix->win);
//         print_map(data);
//         print_player(data);
//         mlx_hook(data->libix->win, 2, 1L << 0, &pressed_key, data);
//         mlx_hook(data->libix->win, 3, 1L << 1, &released_key, data);
//         // mlx_loop_hook(data->libix->mlx, &update, data);
//         mlx_loop(data->libix->mlx);
// }
//         //mlx_hook(data->libix->win, 17, 0, ft_exi, 0);
//         mlx_hook(data->libix->win, 2, 0, ft_exit_key, data);
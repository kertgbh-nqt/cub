/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 06:51:07 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/24 04:41:45 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"
void renderer(t_data *data);

int f_out(void)
{
    exit(0);
    return (0);
}

int keys(int key, t_data *data)
{
    if (key == 53)
        exit(2);
    else if (key == UP)
    {
         P_I -= (M_S * cos(P_P + M_PI / 2));
         P_J -= (M_S * sin(P_P + M_PI / 2));
    }
    else if (key == DOWN)
    {
        P_I += (M_S * cos(P_P + M_PI / 2));
        P_J += (M_S * sin(P_P + M_PI / 2));
    }
    else if (key == LEFT)
    {
        P_I -= (M_S * cos(P_P));
        P_J -= (M_S * sin(P_P));
    }
    else if (key == RIGHT)
    {
        P_I += (M_S * cos(P_P));
        P_J += (M_S * sin(P_P));
    }
    else if (key == TR)
        P_P += T_D;
    else if (key == TL)
        P_P -= T_D;
    return (renderer(data), 0);
}

void print_line(t_data *data)
{
    float new_x;
    float new_y;
    int i;

    i = 0;
    //P_P += T_R;
   // printf ("||PP = %f||\n", P_P);
    new_x = P_I + (sin(P_P) * 30);
    new_y = P_J - (cos(P_P) * 30);
    //printf ("(COS:%f)--(SIN:%f)\n", cos(P_P), sin(P_P));
   // printf ("LBDYA: || new_x : %f||--|| new_y : %f||--||P_I : %f||--||P_J : %f||\n", new_x/64, new_y/64, P_I/64, P_J/64);
    while(i < 30)
    {
        mlx_pixel_put(m_init, m_win, new_y, new_x, BLUE);
       new_x -= sin(P_P);
        new_y += cos(P_P);
        i++;
    }
}

void print_player(t_data *data)
{
    int i;
    int j;

    i = 0;
      while (i < (Lnum * TILE_SIZE))
    {
        j = 0;
        while (j < (LLine * TILE_SIZE))
        {
            if (((i + 2 >= P_I) && (i - 2  <= P_I))&& (((j + 2 >= P_J && j - 2 <= P_J))))
                mlx_pixel_put(m_init, m_win, j, i, BLUE);
            j++;
        }
        i++;
    }
    print_line(data);
}

void print_map(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (i < (Lnum * TILE_SIZE))
    {
        j = 0;
        while (j < (LLine * TILE_SIZE))
        {
            if (!(i % TILE_SIZE) || !(j % TILE_SIZE)) 
                j++;
            else
            {
                if (MAP_P[i / TILE_SIZE][j / TILE_SIZE] == '1')
                    mlx_pixel_put(m_init, m_win, j, i, RED);
                else
                    mlx_pixel_put(m_init, m_win, j, i, GREY);
            j++;
            }
        }
        i++;
    }
    print_player(data);
}

void renderer(t_data *data)
{   
    print_map(data);
}




void    part_graphic(t_data *data)
{
    
    m_init = mlx_init();
    m_win = mlx_new_window(m_init, TILE_SIZE * LLine, TILE_SIZE * Lnum , "CUBE3D");
    mlx_clear_window(m_init, m_win);
    renderer(data);
    mlx_hook(m_win, 2, 0, keys, data);
    mlx_hook(m_win, 17, 0, f_out, data);
    mlx_loop(m_init);
}
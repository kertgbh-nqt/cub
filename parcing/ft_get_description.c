/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_description.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:16:13 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 19:59:23 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cube3d.h"

/*
void    ft_stock_data(t_data *data, char *str)
{
    int i;
    char **split;
    
    i = 0;
    split = ft_split(str, ' ');
    if (!split)
        return ;
    if (!split[0] || split[0][1] == '\n')
        return ;
    if (split[0] && !split[1])
        return (ft_print_fd(2, "empty var description\n"), exit(6));
    if (cmd_with_name_list(split[0]) != 0)
        what_kind_of_fill(data, split);
    else
        return(ft_print_fd(2, "check name of ur description vars\n"), exit(7));
    free_two(split);
}*/

//if value alredy exist what to do ?
/*int cmd_with_name_list(char *name)
{
    if (!ft_strcmp(name, "SO"))
        return (1);
    if (!ft_strcmp(name, "NO"))
        return (1);
    if (!ft_strcmp(name, "WE"))
        return (1);
    if (!ft_strcmp(name, "EA"))
        return (1);
    if (!ft_strcmp(name, "F"))
        return (2);
    if (!ft_strcmp(name, "C"))
        return (2);
    if (!ft_strncmp(name, "1", 1))
        return (3);
    if (!ft_strncmp(name, "0", 1))
        return (3);
    return (0);
}

void    what_kind_of_fill(t_data *data, char **str)
{
    char **strj;
    
    if (cmd_with_name_list(str[0]) == 1)
    {
        if (data->status == 1)
            return (ft_print_fd(2, "description var in wrong place\n"), exit(8));
        if (str[0] && str[1] && str[2])
            return (ft_print_fd(2, "the var "), ft_print_fd(2, str[0]), ft_print_fd(2, "have a pb\n"), exit(9));
        do_description(data, str);
    }
    else if (cmd_with_name_list(str[0]) == 2)
    {
        if (data->status == 1)
            return (ft_print_fd(2, "description var C/F in wrong place\n"), exit(10));
        strj = ft_extra_join(str);
        do_description_2(data , strj);
        free (strj);
    }
    else if (cmd_with_name_list(str[0]) == 3)
        {
            data->status = 1;
            do_map
        }
}
*/

/*void    rm_space_between(str, data)
{
    int i;

    i = 2;
    while ()
}*/

/*int place_data_2(char *str, t_data *data)
{
    if (!ft_strncmp(str, "C", 1)){
            if (data->C != NULL)
                return (ft_print_fd(2, "C DUPLICATED\n"), exit(13), 1337);
            else
                return (13);
            //    rm_space_between(str, data);
    }
    else if ((!ft_strncmp(str, "1", 1)) || (!ft_strncmp(str, "0", 1)))
        return (1);
    else if ((!ft_strncmp(str, "\n", 1)))
        return (1337);
    return ((void)printf("--%s--", str),ft_print_fd(2, "can't parse , unknown var\n"), exit(14), 1337);
};*/


/*int place_data(char *str, t_data *data)
{
    if (!ft_strncmp(str, "SO", 2))
        if (data->SO_str != NULL)
            return (ft_print_fd(2, "SO DUPLICATED\n"), exit(8), 1337);
        else (data->SO_str = str);
    else if (!ft_strncmp(str, "NO", 2))
            if (data->NO_str != NULL)
                return (ft_print_fd(2, "NO DUPLICATED\n"), exit(9), 1337);
            else (data->NO_str = ft_strdup(str));
    else if (!ft_strncmp(str, "WE", 2))
    {
       // printf ("---%s----", str);
            if (data->WE_str != NULL)
                return (ft_print_fd(2, "WE DUPLICATED\n"), exit(10), 1337);
            else (data->WE_str = str);
    }
    else if (!ft_strncmp(str, "EA", 2))
            if (data->EA_str != NULL)
                return (ft_print_fd(2, "EA DUPLICATED\n"), exit(11), 1337);
            else (data->EA_str = str);
    else if (!ft_strncmp(str, "F", 1))
    {
            if (data->F != NULL)
                return (ft_print_fd(2, "WE DUPLICATED\n"), exit(12), 1337);
        
    }
    else
        return (place_data_2(str, data));
          // else
          //      rm_space_between(str, data);
    return (15);
}*/

// int    fill_description(t_data *data)
// {
//     int i;

//     i = 0;
//     while (data->map1[i])
//     {
//         data->map1[i] = ft_strtrim(data->map1[i], " \t");
//         if (place_data(data->map1[i], data) == 1)
//             break;
//         //printf ("%s", data->map1[i]);
//         i++;
//     }
//     return (i);
// }    


//collect those data NO, SO, WE,EA && and F/C
//check if the path exist and can work with it
//check if F/C are 3 and play between 0/255

void    get_len_wei_map(t_mapp *map, int i)
{
    int j;
    
    while (map->map1[i])
    {
        if (map->longer_line < ft_strlen(map->map1[i]))
            map->longer_line = ft_strlen(map->map1[i]);
        map->line_nbr++;
        i++;
    }
    if (map->line_nbr <= 2 || map->longer_line <= 2)
        return (ft_print_fd(2, "error\n"), exit (19));
    map->map2 = (char **)malloc(sizeof(char *) * (map->line_nbr + 1));
    if (!map->map2)
        return (ft_print_fd(2, "error\n"), exit (19));
    printf ("---%d\n------%d\n", map->longer_line, map->line_nbr);
    j = 0;
    while (j <= map->line_nbr)
    {
        map->map2[j] = (char *)malloc(sizeof(char) * (map->longer_line +1));
        if (!map->map2[j])
            return (ft_print_fd(2, "error\n"), exit (19));
        j++;
    }
}
int   fill_second_map(t_mapp *map, int i)
{
    int j;
    int k;

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
  return (i);
}

int go_creat_map(t_data *data, int i)
{
    t_mapp *mapa;


    mapa = data->map;
    get_len_wei_map(mapa, i);
    return (fill_second_map(mapa, i) - 1);
}

void    fill_tabs(t_data *data, char *str)
{
    int fd;
    int i;
    t_mapp *mapa;
    i = 0;
    mapa = data->map;

    mapa->biglen = ft_gnl_size(str);
    mapa->map1 = (char **)malloc(sizeof(char *) * (mapa->biglen + 1));
    if (!mapa->map1)
        return (ft_print_fd(2, "cant allocat for map1\n"), exit(6));
    fd = open(str, O_RDONLY);
    while(1)
    {
        mapa->map1[i] = get_next_line(fd);
        mapa->map1[i] = ft_strtrim(mapa->map1[i], "\n");
        if (mapa->map1[i] == NULL)
            break;
        i++;   
    }
    mapa->map1[i] = NULL;
    close (fd);
}

void    is_the_texture_valid(char *str)
{
    int len;
    char buff[1];
    int fd;
    
    len = ft_strlen(str) - 1;
    if (len <= 4)
        return (ft_print_fd(2 ,str), ft_print_fd(2, " texture too short\n"), exit(21));
    if (str[len] != 'm' || str[len - 1] != 'p' || str[len - 2] != 'x' || str[len - 3] != '.')
        return (ft_print_fd(2, str), ft_print_fd(2, ": invalide textute \n"), exit(20));
    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (ft_print_fd(2, "can't open/find your .xpm map\n"), (void)close(fd), exit(25));
    if (read(fd, buff, 1) == -1)
        return (ft_print_fd(2, "your file xpm is a directory ? \n"), (void)close(fd), exit(26));
    close (fd);
    //open file with mlx content
}

char *get_and_check_texture(char *str, int j)
{
    int start;
    char *ret;

    if (str[j] == '\0')
        return (ft_print_fd(2, "empty var"), (void)write(2, &str[j - 2], 1), (void)write(2, &str[j - 1], 1), (void)write(2, "\n", 1), exit(18), NULL);
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

unsigned long counting(char **str)
{
    int count;
    int tab[3];

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
        return (ft_print_fd(2 , "wrong in the nbr of data in rgb vars\n"), exit(24), 1337);
    return (((tab[0] << 16) | (tab[1] << 8) | tab[2]));
}
unsigned long get_and_handle_clr(char *str, int j)
{
    char **clrs;
    
    if (str[j] != ' ')
        return (ft_print_fd(2, "error\n"), exit(16), 16);
    clrs = ft_split(str + j, ',');
    if (!clrs)
        return (exit(99), 1337);
    return (counting(clrs));
}

int ft_place_data(t_data *data, int i, int j)
{
    char *str;

    str = data->map->map1[i];

    if (str[j] == '\0')
        return (i);
    else if (str[j] == 'S' && str[j + 1] == 'O' && str[j + 2] == ' ' && !(data->map->SO_str))
        data->map->SO_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'W' && str[j + 1] == 'E' && str[j + 2] == ' ' && !(data->map->WE_str))
        data->map->WE_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'E' && str[j + 1] == 'A' && str[j + 2] == ' ' && !(data->map->EA_str))
        data->map->EA_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'N' && str[j + 1] == 'O' && str[j + 2] == ' ' && !(data->map->NO_str))
        data->map->NO_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'C' && str[j + 1] == ' ' && (!data->map->C_rgb))
        data->map->C_rgb = get_and_handle_clr(str, j + 1);
    else if (str[j] == 'F' && str[j + 1] == ' ' && (!data->map->F_rgb))
        data->map->F_rgb = get_and_handle_clr(str, j + 1);
    else if (str[j] == '1' || str[j] == '0')
        return (go_creat_map(data, i));
    else
        return(ft_print_fd(2, "duplcate/invalide input\n"), exit(17), i);
    return (i);
}

void    fill_description(t_data *data)
{
    int i;
    int j;

    i = 0;
    while (data->map->map1[i])
    {
        j = 0;
        while (ft_is_space(data->map->map1[i][j]))
            j++;
        if (ft_strchr( "SWENFC01" , data->map->map1[i][j]))
            i = ft_place_data(data, i, j);
        else if (data->map->map1[i][j] == 0)
            continue;
        else
            return(ft_print_fd(2, "tatcheki had errorn"), exit(16));
        i++;
    }
}

void    ft_get_description(t_data *data, char *str)
{

    fill_tabs(data, str);
    fill_description(data);
    //parsing_tab_two(data);
}

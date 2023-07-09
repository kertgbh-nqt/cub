/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_description.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 03:16:13 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 03:50:50 by mel-garr         ###   ########.fr       */
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



void    fill_tabs(t_mapp *map, char *str)
{
    int fd;
    int i;
    
    i = 0;
    map->biglen = ft_gnl_size(str);
    map->map1 = (char **)malloc(sizeof(char *) * (data->biglen + 1));
    if (!map->map1)
        return (ft_print_fd(2, "cant allocat for map1\n"), exit(6));
    fd = open(str, O_RDONLY);
    while(1)
    {
        map->map1[i] = get_next_line(fd);
        map->map1[i] = ft_strtrim(data->map->map1[i], "\n");
        if (map->map1[i] == NULL)
            break;
        i++;   
    }
    map->map1[i] = NULL;
    close (fd);
}

char *is_the_texture_valid(char *str)
{
    int len;

    len = ft_strlen(str) - 1;
    if (len <= 4)
        return (ft_print_fd(2 ,str), ft_print_fd(2, " texture too short\n"), 2, exit(21));
    if (str[len] != 'm' || str[len - 1] != 'p' || str[len - 2] != 'x' || str[len - 3] != '.')
        return (ft_print_fd(2, str), ft_print_fd(2, ": invalide textute \n"), exit(20), 2);
    //open file with mlx content
    
}

char *get_and_check_texture(char *str, int j)
{
    int start;
    char *ret;
    int fd;

    fd = open(str, O_RDONLY);
    if (fd == -1)
        return (ft_print_fd(2, "can't open/find your .xpm map\n"), (void)close(fd), exit(25));
    if (read(fd, buff, 1) == -1)
        return (ft_print_fd(2, "your file xpm is a directory ? \n"), (void)close(fd), exit(26));
    close (fd);
    if (str[j] == '\0')
        return (fd_print_fd(2, "empty var"), (void)write(2, &str[j - 2], 1), (void)write(2, &str[j - 1], 1), (void)write(2, "\n", 1), 2, exit(18));
    while (str[j] && ((str[j] == ' ') && (str[j] == '\t')))
        j++;
    if (str[j] != 0)
        start = j;
    while (str[j] && str[j] != ' ' && str[j] != '\t')
        j++;
    if (str[j])
        return (fd_print_fd(2, "invalid var\n"), exit(19), 2);
    ret = ft_substr(str, start, j - start + 1);
    is_the_texture_valid(ret);
    return (ret);
}

int ft_count_colors(char *str, int j)
{
    while (str[j])
    {
        while (str[j] && str[j] != ',')
            j++;
        if (str[j] == ',')
            count++;
    }
    if (count != 2)
        return (ft_print_fd(2 , "wrong in the nbr of data in rgb vars\n"), 1337, exit(24));
}
char *get_and_handle_clr(char *str, j)
{
    int start;
    int i;
    char **clrs;
    
    i = 0;
    clrs = (char **)malloc(sizeof (char *) * 3);
    if (clrs)
        return (ft_print_fd(2, "can't allocat\n"), NULL, exit(23));
    if (str[j] == 0 || str[j + 1] == 0)
        return (ft_print_fd(2, "empty color var"), NULL, exit(22));
    ft_count_virgul(str , j);
    clrs = ft_split(str , ",");
    
}

int ft_place_data(t_data *data, int i, int j)
{
    char *str;

    str = data->map->map1[i];

    if (str[j] == '\0')
        return (i);
    else if (str[j] == 'S' && str[j + 1] == 'O' && str[j + 0] == ' ' && !(data->map->SO_str))
        data->map->SO_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'W' && str[j + 1] == 'E' && str[j + 0] == ' ' && !(data->map->WE_str))
        data->map->WE_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'E' && str[j + 1] == 'A' && str[j + 0] == ' ' && !(data->map->EA_str))
        data->map->EA_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'N' && str[j + 1] == 'O' && str[j + 0] == ' ' && !(data->map->NO_str))
        data->map->NO_str = get_and_check_texture(str, j + 2);
    else if (str[j] == 'C' && str[j + 1] == ' ' && (!data->map->C_str))
        data->map->C_rbg = get_and_handle_clr(str, j + 1);
    else if (str[j] == 'F' && str[j + 1] == ' ' && (!data->map->F_str))
        data->map->F_rbg = get_and_handle_clr(str, j + 1);
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
        while (ft_isspace(data->map->map1[i][j]))
            j++;
        if (ft_strchr(data->map->map1[i][j], "SWENFC01"))
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
    int i;
    
    fill_tabs(data->map, str);
    fill_description(data);
}

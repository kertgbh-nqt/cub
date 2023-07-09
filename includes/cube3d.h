/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:22:32 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/09 18:01:48 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE_H
#define CUBE_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif

/*typedef struct s_RGB
{
    int R;
    int G;
    int B;
}t_RGB;*/

typedef struct s_mapp
{
    char *SO_str;
    char *WE_str;
    char *EA_str;
    char *NO_str;
    //char *F_str;
    //char *C_str;
    int biglen;
    char **map1;
    char **map2;
    unsigned long F_rgb;
    unsigned long C_rgb;
    int longer_line;
    int line_nbr;
}t_mapp;

typedef struct s_data
{
    char *str;
    t_mapp *map;
}t_data;


//check_map
void    ft_check_name(char *str);
void    ft_get_description(t_data *data, char *str);

//normale print / basic utils
void    ft_print_fd(int fd, char *str);
int     ft_strlen(char *str);
int     ft_is_space(char c);
int ft_gnl_size(char *str);
void    dup_map1(t_data *data, int len);
char	*ft_strtrim(char *s1, char *set);
int	ft_strncmp(char *s1, char *s2, int n);
char	*ft_strdup(char *s1);
int ft_is_alpha(char *str);
int	ft_atoi(char *str);
char	*ft_substr(char	*s,  int start, int len);
char	**ft_split(char *s, char c);
char	*ft_strchr( char *s, int c);

//get_next_line
char	*gnl_stock(char *str);
char	*gnl_ret(char *str);
char	*big_n(int fd, char *s);
char	*get_next_line(int fd);
int		gnl_check(char *str);
int		gnl_len(char *str);
char	*gnl_link(char *s1, char *s2);
char	*gnl_join(char *s1, char *s2);
void	*coli(int count, int size);

#endif
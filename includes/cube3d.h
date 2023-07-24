/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:22:32 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/24 04:41:02 by mel-garr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef TILE_SIZE 
#  define TILE_SIZE 64
# endif

# ifndef RADIUS
# define RADIUS 3
# endif

typedef struct s_player
{
	float i_p;
	float j_p;
	float  a_p;
	char c_p;
 	double TurnDirection;
	double WalkDirection;
	double MoveSpeed;
	float RotationSpeed;
	float RotationAngle;
	
	int walk_direction_x;
 	int walk_direction_y;
}t_player;

// typedef struct s_player
// {
// 	int				i_p;
// 	int				j_p;
// 	char			c_p;
// 	//vid
// 	float radius; //size of player 3/4 pxl dyal dwara li rado ncreer
// 	int init_view;
// 	int TurnDirection; // -1 / +1 left / right an3awed nchofuha
// 	int WalkDirection; // -1 if back +1 if front // smae
// 	float RotationAngle ;
// 	float MoveSpeed ;
// 	float RotationSpeed;
// 	//zid rewen
// 	int walk_direction_x;
// 	int walk_direction_y;
	
// }					t_player;

//w 13 d 2 s 1 a 0

# define UP 13
# define DOWN 1
# define LEFT 2
# define RIGHT 0

# define TR 123
# define TL 124

# define BG "background.xpm"
# define WL "wall.xpm"
# define PL "up.xpm"

# define GREY 0x808080
# define RED 0xA52A2A
# define BLUE 0x0000FF


# define m_init data->libix->init
# define m_win data->libix->win
# define LLine data->map->longer_line
# define Lnum data->map->line_nbr
# define P_I  data->player->i_p 
# define P_J data->player->j_p 
# define P_P data->player->a_p
# define M_S data->player->MoveSpeed
# define MAP_P data->map->map2
# define T_D data->player->TurnDirection

typedef struct s_p
{
	void *init;
	void *win;
	char **map;
	int WW;
	int WH;
	int PLAYER_X;
	int PLAYER_Y;
	float FOV_angle;
	int TurnDirection;
	int WalkDirection;
	float WalkSpeed;
	float TurnSpeed;
	float RotationAngle;
}					t_p;

typedef struct s_mapp
{
	char			*so_str;
	char			*we_str;
	char			*ea_str;
	char			*no_str;
	int				biglen;
	char			**map1;
	char			**map2;
	unsigned long	f_rgb;
	unsigned long	c_rgb;
	int				longer_line;
	int				line_nbr;
	int				into_map;
}					t_mapp;

typedef struct s_lib
{
	void	*init;
	void	*win;
	void	*img1;
	void	*img0;
	void	*imgp;
	
}				t_lib;

typedef struct s_data
{
	char			*str;
	t_mapp			*map;
	t_player		*player;
	t_lib			*libix;
}					t_data;

// check_map
void				ft_check_name(char *str);
void				ft_get_description(t_data *data, char *str);
void				fill_tabs(t_data *data, char *str);
void				fill_description(t_data *data);
unsigned long		get_and_handle_clr(char *str, int j);
int					go_creat_map(t_data *data, int i);

// normale print / basic utils
void				ft_print_fd(int fd, char *str);
int					ft_strlen(char *str);
int					ft_is_space(char c);
int					ft_gnl_size(char *str);
void				dup_map1(t_data *data, int len);
char				*ft_strtrim(char *s1, char *set);
int					ft_strncmp(char *s1, char *s2, int n);
char				*ft_strdup(char *s1);
int					ft_is_alpha(char *str);
int					ft_atoi(char *str);
char				*ft_substr(char *s, int start, int len);
char				**ft_split(char *s, char c);
char				*ft_strchr(char *s, int c);
int					is_in_wrong_place(int i, int j, char **str);
int					norm(char *str, int i, char c);


//graphic part
void    part_graphic(t_data *data);


// get_next_line
char				*gnl_stock(char *str);
char				*gnl_ret(char *str);
char				*big_n(int fd, char *s);
char				*get_next_line(int fd);
int					gnl_check(char *str);
int					gnl_len(char *str);
char				*gnl_link(char *s1, char *s2);
char				*gnl_join(char *s1, char *s2);
void				*coli(int count, int size);

#endif
//zid partyia n9ess empty lane felekher
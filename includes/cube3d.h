/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-garr <mel-garr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 02:22:32 by mel-garr          #+#    #+#             */
/*   Updated: 2023/07/15 01:20:50 by mel-garr         ###   ########.fr       */
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

typedef struct s_player
{
	int				i_p;
	int				j_p;
	char			c_p;
	//vid
	float radius; //size of player 3/4 pxl
	int TurnDirection; // -1 / +1 left / right 
	int WalkDirection; // -1 if back +1 if front
	float RotationAngle ;
	float MoveSpeed ;
	float RotationSpeed;
	
}					t_player;

# define BG "background.xpm"
# define WL "wall.xpm"
# define PL "up.xpm"

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
	void	*mlx;
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
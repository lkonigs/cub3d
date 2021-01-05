/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkonig <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/27 15:26:59 by lkonig            #+#    #+#             */
/*   Updated: 2020/10/27 15:27:18 by lkonig           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define FOV 		60
# define PMS		4.0
# define PTS		4
# define WH			64

# include <fcntl.h>
# include <stdlib.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibX/mlx.h"

typedef struct		s_multiint
{
	int				x;
	int				y;
}					t_multiint;

typedef struct		s_multidouble
{
	double			x;
	double			y;
}					t_multidouble;

typedef struct		s_player
{
	t_multiint		pos;
	double			angle;
	t_multidouble	dir;
}					t_player;

typedef struct		s_plane
{
	double			dist;
	double			angles;
	t_multidouble	vect;
}					t_plane;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
}					t_img;

typedef struct		s_point
{
	t_multidouble	pos;
	int				col;
	double			dist;
	char			text;
}					t_point;

typedef struct		s_sprite
{
	t_multiint		pos;
	double			dist;
	int				visible;
	int				col;
	int				midcol;
	int				maxcol;
}					t_sprite;

typedef struct		s_param
{
	char			**tempmap;
	char			**map;
	char			*no_text;
	char			*so_text;
	char			*ea_text;
	char			*we_text;
	char			*sp_text;
	t_multiint		mapsize;
	int				*fcol;
	int				*ccol;
	t_multiint		res;
	t_multiint		screen_res;
	t_player		player;
	t_plane			plane;
	void			*mlx_ptr;
	void			*win_ptr;
	void			*imgptr;
	char			*imgstr;
	t_sprite		sprites[100];
	double			distbuf[50000];
	unsigned int	nb_sprite;
}					t_param;

typedef struct		s_wall
{
	long long		height;
	t_multidouble	pos;
	char			text;
	int				offset;
	double			heat;
	double			dist;
}					t_wall;

typedef struct		s_spwall
{
	long long		height;
	int				width;
	t_multidouble	pos;
	int				offset;
	double			heat;
	t_multiint		screen;
	t_multiint		drawst;
	t_multiint		drawend;
}					t_spwall;

int					open_configfile(int argc, char **argv, int *save);
int					get_j(t_wall w, t_param *param, double *pix);
int					get_rgb(int color);
char				*set_text(t_wall w, t_param *param);
void				set_mid(t_wall w, char *str, t_param *param);
double				set_col(t_param *param, t_wall w, char *str);
t_wall				set_wall(t_param *param, t_point p, int col);
void				display(t_param *param, int save);
int					create_image(t_param *param);
int					upd_image(t_param *param);
void				error_init(int i);
void				error(int i, t_param *param);
void				ft_exit(t_param *param);
int					deal_key(int key, void *param);
void				move(t_param *param, int type);
void				apply_move(int max_pos, int gv_pos, int k, t_param *param);
void				apply_text(char *str, char *text, int i, int j);
int					deal_end(void *param);
void				init_param(t_param *param);
int					init_player(t_param *param, char dir, int pos_x, int pos_y);
t_point				init_ptv(double angle, t_point b, t_param *p, double tan);
t_point				init_pth(double angle, t_point a, t_param *p, double tan);
void				init_sprite(t_param *param, unsigned int k);
t_point				intersection(t_param *param, int col, double angle);
double				set_tan(double angle);
t_point				inter_v(t_param *param, double angle, double t_ang, int c);
t_point				inter_h(t_param *param, double ang, double tan, t_point b);
t_point				inter_cmp(t_point a, t_point b, t_param *p, double angle);
int					get_finalmap(t_param *param);
int					parse_map(char *line, t_param *param);
void				check_map(t_param *param, int i, int j, int type);
int					check_inter_sp(t_point b, t_param *param, unsigned int k);
int					parse_res(char *line, t_param *param);
void				res_comp(int tmp, t_param *param, int i);
void				parse_col(char *line, t_param *param);
int					parse_text(char *line, t_param *param);
void				parse_configfile(int fd, t_param *param);
void				parse_free(char *line, t_param *param);
void				parse_configline(char *line, t_param *param);
void				ft_save(t_param *param, char *pathname);
void				set_bmpheader(t_param *param, int fd);
void				turn(t_param *param, int key);
void				ft_north_texture(t_param *param, char *line, int i);
void				ft_south_texture(t_param *param, char *line, int i);
void				ft_east_texture(t_param *param, char *line, int i);
void				ft_west_texture(t_param *param, char *line, int i);
void				ft_sprite_texture(t_param *param, char *line, int i);
void				nb_sprite(t_param *param);
void				ft_sprite(t_param *param);
void				ft_switch(t_param *param, int k, int n);
void				sort_sprite(t_param *param);
int					check_sp(t_param *param, int i, int j, unsigned int k);
int					inter_sprite(t_param *param, double angle, int col, int k);
int					inter_sp_h(t_param *p, double ang, int c, unsigned int k);
int					inter_sp_v(t_param *p, double ang, int c, unsigned int k);
void				update_col(t_param *param, t_spwall sp, char *str);
t_spwall		set_sprite(t_param *param, int k, t_multidouble transform, int screenx);
void				get_sprite(t_param *param, int i, int j, unsigned int k);
void				display_sprite(t_param *param);
void				error_more(int i);
double				set_angle(double angle);
void				set_sprite_info(t_param *param, int k, int col);
t_point				update_pointv(t_point b, double angle, double tan_angle);
t_point				update_pointh(t_point a, double angle, double tan_angle);
double				update_dist(t_point a, t_param *param);
void				update_wall(t_spwall sp, char *str, t_param *param);
void				correct_sprite(t_param *p);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ghar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:16:21 by mel-ghar          #+#    #+#             */
/*   Updated: 2020/01/26 17:54:58 by mel-ghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdio.h>

typedef struct
{
	int			lookup;
	int			lookdown;
	int			up;
	int			down;
	int			left;
	int			right;
}				t_keys;

typedef struct
{
	double		x;
	double		y;
}				t_point;

typedef struct
{
	int			r;
	int			tofirstline;
	int			err;
	char		*help;
	int			c;
	int			width;
	int			height;
	int			map_lines;
	int			sprite_num;
	int			squarewidth;
	int			squareheight;
	char		**maplines;
}				t_map_info;

typedef struct	s_tuto
{
	int			**img;
	int			*test;
	int			*width;
	int			*height;
}				t_txt_color;

typedef struct
{
	int			up;
	int			down;
	int			right;
	int			left;
	int			sup;
	int			sdown;
	int			sleft;
	int			sright;
	int			spec;
	double		angel;
	int			a;
}				t_dir;

typedef struct	s_coco
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
}				t_acc;

typedef struct	s_koko
{
	char		*north;
	int			n;
	char		*south;
	int			s;
	char		*weast;
	int			w;
	char		*east;
	int			e;
	char		*sprite;
	int			sp;
	int			floor;
	int			celling;
}				t_name_text;

typedef struct
{
	int			i;
	int			look;
	int			divid;
	t_keys		*keys;
	double		splength;
	int			offset;
	int			hit;
	int			index;
	int			stop;
	int			lr[2];
	int			wasvert;
	double		radius;
	double		angel;
	int			numobj;
	double		length;
	t_txt_color	txtcolor;
	t_point		pos;
	t_point		help;
	t_point		vert;
	t_point		horz;
	t_acc		acc;
	t_map_info	map;
	t_name_text	txt;
}				t_player;

void			rest_keys(t_keys *keys);
int				handel_txt(t_name_text *txt, char *mapname, t_map_info *map);
int				handel_north(char *line, char **str);
int				fill_map_info(t_player *pl, char *mapname);
char			*str_cat_txt(char *str, int *len);
int				help_get_color_map(char *line, t_name_text *txt, int a);
int				handel_rgb_int(char *str, int i, int check);
int				help_short3(char *str, int *i1, int *check);
int				help_short4(char *str, int *len, int *color, int i);
int				help_short5(char *str, int *i1, int a, int *check);
int				is_player(char *line, int *obj);
int				rest_info(t_map_info *map, t_name_text *txt, int *i);
int				handel_rest_txt(char *line, char **str);
int				handel_rest_of_txt(t_name_text *txt, t_map_info *map,
				int fd, char *line);
int				str_cmp(char *s1, char *s2, int len);
int				is_alpha(char c);
int				is_digit(char c);
int				ft_atoi(char *str, int *len);
void			ft_putstr(char *str);
int				resolution(char *name, t_map_info *map, int i);
int				helpresolution(t_map_info *map, char *line);
int				repeat_error(t_name_text txt, int a, int r);
int				short_help1(char **help, char *line);
int				help_rest1(t_name_text *txt, t_map_info *map,
				int fd, char *line);
int				handel_resol_error(int check);
int				help_rest2(t_name_text *txt, t_map_info *map,
				int fd, char *line);
void			handel_width(t_map_info *map);
int				handel_map_lines(t_map_info *map, int fd, int cnum);
int				handel_line_per_line(char *line, int a);
int				is_one_of_map(char c);
int				help_short1(char *line, int *counter, int *i1);
int				fill_map_lines(char *mapname, t_map_info *map);
char			*line_no_space(char *line, int length);
int				last_line(char *line);
int				player_repeat(char **str, int *numsp);
int				help_fill_map(t_player *pl);
void			handel_numbers(int *numlines, int *numcolors, char *line);
int				handel_sp_bounds(t_player *pl);
void			handel_lr(int *num, int fd, int numlines, int *right);
void			handel_one_line_lr(char *line, int *lcount,
				int *rcount, int length);
int				fill_void_data(t_player *pl);
int				is_player_i(char c);
void			draw_one_line(t_player *pl, char *line);
int				draw_world(t_player *pl);
void			handel_player_info(t_player *pl, char c);
void			draw_player_vew(t_player *pl);
void			draw_player_vew(t_player *pl);
int				draw_rays(t_player *pl, int i);
double			raycasting(t_player *pl, double angel);
double			handel_angel(double angel);
void			handel_dirction(t_dir *dir, double angel);
void			rest_dir_info(t_dir *dir);
void			first_step(t_point *p, t_dir dir, t_player *pl, double angel);
double			calculate_length(double x1, double y1, double x2, double y2);
int				open_images(t_player *pl);
int				help_open_img(t_player *pl);
int				is_in_screen(t_point p, double width, double heigth);
int				is_there_wall(t_map_info *map, double x, double y,
				t_point *hitpos);
void			small_help(int h, t_point *p, t_dir dir);
double			handel_bet_ang(t_point p1, t_point p2, t_point p3,
				double *angel);
t_point			handel_rotate_point(t_point on, t_point to, double angel);
t_point			handel_sidepoint(t_point center, double radius, double angel);
int				is_inrange(t_point newp, t_point center, double radius);
void			help_horz_raycast(t_dir *dir, t_point *inp,
				t_point *p, t_player *pl);
double			help_horz_ret(t_point inp, t_dir *dir, t_player *pl, int a);
double			horz_raycast(t_point p, t_dir dir, t_player *pl, double angel);
double			vert_raycast(t_dir dir, t_player *pl, double angel);
void			handel_sprite_new(t_point *hit, t_player *pl, t_point center,
				t_dir dir);
double			vert_raycast(t_dir dir, t_player *pl, double angel);
double			help_vert_loop(t_point p, t_player *pl, t_dir dir,
				double angel);
void			help_vert_raycast(t_player *pl, t_point *p,
				t_point *inp, t_dir *dir);
double			horz_raycast(t_point p, t_dir dir, t_player *pl, double angel);
double			handel_raylength(double length_h, double length_v,
				t_player *pl);
void			draw_3world(double length, t_player *pl, int x, int d);
double			virtual_height(t_player *pl, double *y, int *i,
				double *tmpheight);
int				txt_color(t_player *pl, int x, int itxt, double height);
int				tran(int color, double length, int d);
void			put_pixel(t_player pl, int x, int y, int color);
int				sprite_color(t_player *pl, int i, double height);
void			draw_sprite(t_player *pl, int x, int i, double y1);
void			help_draw_world(int i, t_player *pl, double length, int x);
void			clear(t_player **ptr);
int				key_press(int key, t_player *pl);
int				key_rel(int key, t_keys *keys);
int				goout(int key, t_player *pl);
int				key_move(t_player *pl);
int				can_move(t_player *pl, char c, double speed, t_point *newp);
int				check_save(char *str);
int				my_bitmap(t_player pl);
void			test(t_player pl, unsigned char **buf,
				int width_in_bytes, int color);
int				is_valid_name(char *str);
void			*ft_memcpy(void *dest, const void *sourc, size_t size);
void			*my_calloc(int a, int b);
int				get_color(int y, int x, void *img_ptr, int width);
int				handel_size_in_bytes(int width, int height, int *w);
void			help_bitmap(t_player pl, char **header, int *all);
int				my_bitmap(t_player pl);
int				tran_color(int color, int r, int g, int b);
void			test(t_player pl, unsigned char **buf1, int width_in_bytes,
				int color);

#endif

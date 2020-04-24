/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsantoni <tsantoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/22 10:09:43 by tsantoni          #+#    #+#             */
/*   Updated: 2020/04/24 09:47:07 by tsantoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "math.h"
# include "./libft/get_next_line.h"
# include "./libft/libft.h"

# define OK 1
# define ERROR 0

# define KEY_Z 122
# define KEY_Q 113
# define KEY_S 115
# define KEY_D 100
# define KEY_W 119
# define KEY_A 97
# define ESC 65307

# define KEY_UP 65362
# define KEY_LEFT 65361
# define KEY_DOWN 65364
# define KEY_RIGHT 65363

# ifndef MOVE_SPEED
#  define MOVE_SPEED 0.11
# endif

# ifndef ROT_SPEED
#  define ROT_SPEED 0.11
# endif

# ifndef MOVE_SPRITE
#  define MOVE_SPRITE 64
# endif

# ifndef H_DIV
#  define H_DIV 1
# endif

# ifndef W_DIV
#  define W_DIV 1
# endif

typedef struct	s_bmp{
	int			fd;
	int			fsize;
	int			zero;
	int			offset;
	int			hsize;
	int			w;
	int			h;
	short int	pln;
	short int	bpp;
}				t_bmp;

typedef struct	s_map{
	char	**tab;
	char	**cpy;
	int		h;
	int		w;
}				t_map;

typedef struct	s_vec{
	double	x;
	double	y;
}				t_vec;

typedef struct	s_rgb{
	int	r;
	int	g;
	int	b;
}				t_rgb;

typedef struct	s_tmp{
	t_list	*lst;
	int		clean_w;
	int		prev_x;
	int		i;
	int		j;
}				t_tmp;

typedef struct	s_win{
	void	*ptr;
	int		x;
	int		y;
}				t_win;

typedef struct	s_img{
	void	*ptr;
	int		*add;
}				t_img;

typedef struct	s_mlx{
	void	*ptr;
	t_win	*win;
	t_img	*img;
}				t_mlx;

typedef struct	s_col{
	unsigned int	f;
	unsigned int	c;
	unsigned int	w;
	unsigned int	spr;
}				t_col;

typedef struct	s_key{
	int	left;
	int	right;
	int	up;
	int	down;
	int	rotate_left;
	int	rotate_right;
}				t_key;

typedef struct	s_tex{
	void	*ptr;
	char	*add;
	char	*file;
	int		w;
	int		h;
	int		x;
	int		y;
}				t_tex;

typedef	struct	s_sp{
	double	x;
	double	y;
	double	dist;
	int		*img_add;
}				t_sp;

typedef struct	s_sp_inf{
	t_sp	*curr;
	double	x;
	double	y;
	double	inv;
	t_vec	*trans;
	int		screen;
	int		line_w;
	int		line_h;
	t_vec	*start;
	t_vec	*end;
	int		move_screen;
}				t_sp_inf;

typedef struct	s_scene{
	t_mlx		*mlx;
	t_tmp		*p;
	t_col		*col;
	t_map		*map;
	t_vec		*pos;
	t_vec		*dir;
	t_vec		*pln;
	t_vec		*ray;
	t_vec		*sqr;
	t_rgb		*rgb;
	t_vec		*sde_dst;
	t_vec		*dlt_dst;
	t_vec		*stp;
	double		prp_dst;
	double		cam;
	int			hit;
	int			sde;
	double		line_h;
	int			pix_start;
	int			pix_end;
	int			tex_start;
	int			tex_end;
	t_vec		*wall;
	double		*zbuf;
	t_tex		*tex_n;
	t_tex		*tex_s;
	t_tex		*tex_w;
	t_tex		*tex_e;
	t_tex		*tex_spr;
	int			spr_nb;
	t_sp		**sp;
	t_sp_inf	*sp_inf;
	int			*spr_order;
	t_bmp		*bmp;
	t_key		*key_buf;
	int			*elmts;
}				t_scene;

void			init_bmp(t_scene *s);
void			write_pixel_data(t_scene *s);
int				write_header(t_scene *s);
void			save_bmp(t_scene *s);

int				check_cub(char *file);
int				check_xpm(char *file);
void			check_elements(t_scene *s);
int				count_elements(t_scene *s);
void			increment_elmts(t_scene *s, char c);

void			copy_map_row(t_scene *s, int i, int j);
void			copy_map(t_scene *s);
int				check_map(t_scene *s, int x, int y);

void			exit_err_1(int err_nb);
void			exit_err_2(int err_nb);

int				destroy_notify(t_scene *s);
int				key_press(int key, t_scene *s);
int				key_release(int key, t_scene *s);
int				key_dispatch(t_scene *s);

void			manage_sprites(t_scene *s);
void			draw_world(t_scene *s);
void			draw_img(t_scene *s);

int				move_forward(t_scene *s);
int				move_backward(t_scene *s);
int				move_left(t_scene *s);
int				move_right(t_scene *s);

void			parse_color(t_scene *s, char *line, int *i, char c);
void			parse_res(t_scene *s, char *line, int *i);
void			dispatch_non_map(t_scene *s, char *line, int *i);
void			dispatch_parsing(t_scene *s, char *line, int *i);
void			parsing(t_scene *s, int fd);

void			check_map_char(t_scene *s, char c);
int				get_clean_width(char *line);
char			*clean_line(char *line, t_scene *s);
int				fill_list(t_scene *s, char *line);
int				parse_list(t_scene *s, char *line, int fd);

void			init_sprite(t_scene *s, int i, int j);
void			init_player(t_scene *s, int i, int j);
void			init_pos_on_map(t_scene *s);
void			get_map_size(t_scene *s);
int				fill_map(t_scene *s);

void			init_values_from_ray(t_scene *s, int i);
void			cast_ray_further(t_scene *s);
void			locate_wall_start_and_end(t_scene *s);
void			pick_wall_texture_color(t_scene *s, t_tex *t);
void			overwrite_world_pixel(t_scene *s, int i, int j);

int				rotate_right(t_scene *s);
int				rotate_left(t_scene *s);

void			swap_sprites(t_scene *s, int n1, int n2);
void			order_sprites(t_scene *s);
void			locate_sprite_start_and_end(t_scene *s);
void			cast_sprite(t_scene *s);
void			overwrite_sprite_pixel(t_scene *s, int x);

void			init_sp_inf(t_scene *s, int n);

void			create_win(t_win **win);
void			create_img(t_img **img);
void			create_mlx(t_mlx **mlx);
void			create_tex(t_tex **tex);
void			create_key(t_key **key_buf);

void			create_map(t_map **map);
void			create_rgb(t_rgb **rgb);
void			create_col(t_col **col);
void			create_tmp(t_tmp **p);
void			create_vec(t_vec **vec);

void			create_sp(t_sp **sp);
void			create_sp_inf(t_sp_inf **sp_inf);
void			create_bmp(t_bmp **bmp);
void			init_scene(t_scene **s);
void			create_scene(t_scene **s);

void			get_textures_add(t_scene *s);
void			init_textures_ptr(t_scene *s);
char			*ft_substr_word(char *line, unsigned int start, size_t len);
int				get_check_tex(char **file, char *line, int *i);
int				parse_texture(t_scene *s, char *line, int *i, char c);

int				check_range(int nb, int min, int max);
unsigned int	convert_color(int r, int g, int b);
int				ft_atoi_ptr(char const *s, int *i);

void			ft_max(int *nb, int max);
void			ft_min(int *nb, int min);
int				ft_is_space(char c);
void			skip_space(char *line, int *i);
void			skip_space_char(char *line, int *i, char c);

#endif

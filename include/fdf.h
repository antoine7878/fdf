/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:30:15 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 18:31:25 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stddef.h>

# define WIDTH 1280
# define HEIGHT 720

# define AST30 0.6154797086
# define CAT2 0.4472135955
# define SAT2 0.894427191

# define TRIG_PREC 1000

typedef float	t_point[5];

enum
{
	x,
	y,
	z,
	c,
	cl
};

typedef struct s_move
{
	float		ro_x;
	float		ro_y;
	float		ro_z;
	float		tr_x;
	float		tr_y;
	float		tr_z;
	float		scaling;
}				t_move;

typedef struct s_map
{
	int			col_count;
	int			row_count;
	float		x_min;
	float		x_max;
	float		y_min;
	float		y_max;
	float		z_min;
	float		z_max;
	float		tr_valx;
	float		tr_valy;
	t_point		**data;
}				t_map;

typedef struct s_img
{
	void		*ptr;
	char		*data;
	int			bit_per_pixel;
	int			size_line;
	int			endian;
	size_t		data_len;
}				t_img;

typedef struct s_fdf
{
	int			mouse_x;
	int			mouse_y;
	int			shift;
	int			is_oblique;
	void		*mlx;
	void		*win;
	t_img		*img;
	t_map		*map;
	t_move		*move;
}				t_fdf;

// fdf.c
void			center(t_fdf *fdf);

// color.c
int				average_color(int c1, int c2, unsigned char weight);
void			update_map_color(t_map *map, int c_min, int c_max);

// control.c
int				close_all(t_fdf *fdf);
void			*initilatize_fdf(t_fdf *fdf, char *win_title);

// map.c
void			free_map(t_map *map);
void			iterijmap(t_map *map, void (*f)(t_map *, int, int));
int				parse_map_data(t_map *map, int fd);
int				parse_args(char *file, t_map *map);

// map_limits.c
void			get_map_limits(t_map *map);
void			get_limits_z(t_map *map, int i, int j);

// put_utlis.c
void			put_map(t_fdf *fdf);
void			put_pixel(t_img *img, int x, int y, int color);
void			put_line(t_img *img, t_point start, t_point end);
float			distance(float a, float b);

// split_atoi.c
t_point			*ft_split_coords(char const *s, int *col_count, int row);
int				cout_line(char *file);
int				parse_args(char *file, t_map *map);

// transform.c
void			rotate_x(t_point pt, float dir);
void			rotate_y(t_point pt, float dir);
void			rotate_z(t_point pt, float dir);
void			translate_pt(t_point pt, float tr_x, float tr_y);
void			zoom_pt(t_point pt, float scaling);

// on_mouse.c
int				on_mouse_down(int button, int x, int y, t_fdf *fdf);
int				on_mouse_move(int x, int y, t_fdf *fdf);
int				on_mouse_up(int x, int y, t_fdf *fdf);

void			reset_iso(t_fdf *fdf);

// on_key.c
int				on_key_down(int key, t_fdf *fdf);
int				on_key_up(int key, t_fdf *fdf);

// trigo.c
float			ft_cos(float angle);
float			ft_sin(float angle);

#endif

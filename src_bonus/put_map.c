/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:52:36 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:59:55 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/include/libft.h"
#include "../minilibx-linux/mlx.h"
#include <stdlib.h>

static void	slide(t_point pt, t_fdf *fdf, int dir)
{
	pt[x] += dir * (fdf->map->x_max - fdf->map->x_min) / 2;
	pt[y] += dir * (fdf->map->y_max - fdf->map->y_min) / 2;
	pt[z] += dir * (fdf->map->z_max - fdf->map->z_min) / 2;
}

static int	is_in_screen(t_point pt)
{
	if (pt[x] < 0 || pt[x] > WIDTH || pt[y] < 0 || pt[y] > HEIGHT)
		return (0);
	return (1);
}

static void	put_pt_lines(t_fdf *fdf, int i, int j, t_point *pts)
{
	ft_memcpy(pts[0], fdf->map->data[i][j], sizeof(t_point));
	slide(pts[0], fdf, -1);
	rotate_z(pts[0], fdf->move->ro_z);
	rotate_x(pts[0], fdf->move->ro_x);
	rotate_y(pts[0], fdf->move->ro_y);
	zoom_pt(pts[0], fdf->move->scaling);
	slide(pts[0], fdf, 1);
	translate_pt(pts[0], fdf->move->tr_x, fdf->move->tr_y);
	if (fdf->is_oblique)
	{
		pts[0][x] += 1.0 / 2 * pts[0][z] * CAT2;
		pts[0][y] += 1.0 / 2 * pts[0][z] * SAT2;
	}
	// if (is_in_screen(pts[0]))
	// 	put_pixel(fdf->img, pts[0][x], pts[0][y], pts[0][c]);
	if (i > 0 && (is_in_screen(pts[0]) || is_in_screen(pts[j + 1])))
		put_line(fdf->img, pts[0], pts[j + 1]);
	if (j + 1 > 0 && (is_in_screen(pts[0]) || is_in_screen(pts[j])))
		put_line(fdf->img, pts[0], pts[j]);
	ft_memcpy(pts[j + 1], pts[0], sizeof(t_point));
}

void	put_map(t_fdf *fdf)
{
	int		i;
	int		j;
	t_point	*pts;

	pts = malloc(sizeof(t_point) * (fdf->map->col_count + 1));
	if (!pts)
		return ;
	ft_bzero(fdf->img->data, fdf->img->data_len);
	i = -1;
	while (++i < fdf->map->row_count)
	{
		j = -1;
		while (++j < fdf->map->col_count)
			put_pt_lines(fdf, i, j, pts);
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img->ptr, 0, 0);
	free(pts);
}

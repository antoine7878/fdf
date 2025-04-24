/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:47:43 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:33:59 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	close_all(t_fdf *fdf)
{
	if (fdf->mlx && fdf->img && fdf->img->ptr)
		mlx_destroy_image(fdf->mlx, fdf->img->ptr);
	if (fdf->mlx && fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->mlx)
	{
		mlx_destroy_display(fdf->mlx);
		free(fdf->mlx);
	}
	if (fdf->map)
		free_map(fdf->map);
	exit(0);
}

static void	attach_hooks(t_fdf *fdf)
{
	mlx_hook(fdf->win, DestroyNotify, NoEventMask, close_all, fdf);
	mlx_hook(fdf->win, MotionNotify, Button1MotionMask, on_mouse_move, fdf);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, on_key_down, fdf);
	mlx_hook(fdf->win, KeyRelease, KeyReleaseMask, on_key_up, fdf);
	mlx_hook(fdf->win, ButtonPress, ButtonReleaseMask, on_mouse_down, fdf);
	mlx_mouse_hook(fdf->win, on_mouse_down, fdf);
}

void	*initilatize_fdf(t_fdf *fdf, char *win_title)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		return (close_all(fdf), NULL);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, win_title);
	if (!fdf->win)
		return (close_all(fdf), NULL);
	attach_hooks(fdf);
	fdf->img->ptr = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img->ptr)
		return (close_all(fdf), NULL);
	fdf->img->data = mlx_get_data_addr(fdf->img->ptr,
			&(fdf->img->bit_per_pixel), &(fdf->img->size_line),
			&(fdf->img->endian));
	if (!fdf->img->data)
		return (close_all(fdf), NULL);
	fdf->img->data_len = WIDTH * HEIGHT / 8 * fdf->img->bit_per_pixel;
	return (fdf->win);
}

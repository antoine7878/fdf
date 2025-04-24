/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:03:52 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 12:08:50 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../include/keys.h"
#include "../minilibx-linux/mlx.h"
#include <math.h>

static int	on_key_down_1(int key, t_fdf *fdf)
{
	if (key == ESC)
		return (mlx_loop_end(((t_fdf *)fdf)->mlx), 1);
	else if (key == K_SHIFT)
		return (fdf->shift = 5, 1);
	else if (key == K_A)
		return (fdf->move->tr_x -= fdf->map->tr_valx, 1);
	else if (key == K_D)
		return (fdf->move->tr_x += fdf->map->tr_valx, 1);
	else if (key == K_I)
		return (fdf->move->scaling += 0.1, 1);
	else if (key == K_K)
		return (fdf->move->scaling -= 0.1, 1);
	else if (key == K_O)
		return (reset_iso(fdf), 1);
	else if (key == K_B)
		return (fdf->is_oblique = 1, 1);
	else if (key == K_W)
		return (fdf->move->tr_y -= fdf->map->tr_valy, 1);
	else if (key == K_S)
		return (fdf->move->tr_y += fdf->map->tr_valy, 1);
	return (0);
}

static int	on_key_down_2(int key, t_fdf *fdf)
{
	if (key == K_Q)
		fdf->move->ro_z = fmod(fdf->move->ro_z + 0.02, 2 * M_PI);
	else if (key == K_E)
		fdf->move->ro_z = fmod(fdf->move->ro_z - 0.02, 2 * M_PI);
	put_map(fdf);
	return (0);
}

int	on_key_down(int key, t_fdf *fdf)
{
	if (on_key_down_1(key, fdf))
		put_map(fdf);
	else
		on_key_down_2(key, fdf);
	return (0);
}

int	on_key_up(int key, t_fdf *fdf)
{
	if (key == K_SHIFT)
		fdf->shift = 1;
	return (0);
}

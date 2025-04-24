/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perifs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 18:08:46 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 12:04:43 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/include/libft.h"
#include <math.h>
#include <stdio.h>

static void	rotate_axis(float *ro, int dir, t_fdf *fdf)
{
	*ro = fmod(*ro - dir * (0.005 * fdf->shift), 2 * M_PI);
}

void	reset_iso(t_fdf *fdf)
{
	fdf->is_oblique = 0;
	update_map_color(fdf->map, 0x00FF0000, 0x0000FF00);
	ft_memcpy(fdf->move, &(t_move){-AST30, 0, -M_PI_4, 0, 0, 0, 0},
		sizeof(float) * 3);
	center(fdf);
}

int	on_mouse_down(int button, int x, int y, t_fdf *fdf)
{
	fdf->mouse_x = x;
	fdf->mouse_y = y;
	if (button == 4)
		fdf->move->scaling += 0.1 * fdf->shift;
	else if (button == 5)
		fdf->move->scaling -= 0.1 * fdf->shift;
	put_map(fdf);
	return (0);
}

int	on_mouse_move(int x, int y, t_fdf *fdf)
{
	if (x - fdf->mouse_x > 0)
		rotate_axis(&fdf->move->ro_y, -1, fdf);
	if (x - fdf->mouse_x < 0)
		rotate_axis(&fdf->move->ro_y, 1, fdf);
	if (y - fdf->mouse_y > 0)
		rotate_axis(&fdf->move->ro_x, 1, fdf);
	if (y - fdf->mouse_y < 0)
		rotate_axis(&fdf->move->ro_x, -1, fdf);
	fdf->mouse_x = x;
	fdf->mouse_y = y;
	put_map(fdf);
	return (0);
}

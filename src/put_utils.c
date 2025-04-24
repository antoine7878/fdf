/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:30:49 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:53:33 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

float	distance(float a, float b)
{
	if (a > b)
		return (a - b);
	return (b - a);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	int	a;

	a = (x * img->bit_per_pixel / 8) + y * img->size_line;
	if (x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
		*(int *)(img->data + a) = color;
}

void	put_line(t_img *img, t_point start, t_point end)
{
	float	step_x;
	float	step_y;
	float	step_c;
	float	steps;
	int		i;

	steps = fmax(distance(start[x], end[x]), distance(start[y], end[y]));
	step_x = (end[x] - start[x]) / steps;
	step_y = (end[y] - start[y]) / steps;
	step_c = (255.0) / steps;
	i = -1;
	while (i++ < steps)
		put_pixel(img, start[x] + step_x * i, start[y] + step_y * i,
			average_color(end[c], start[c], i * step_c));
}

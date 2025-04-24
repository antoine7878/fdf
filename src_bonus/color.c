/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 20:41:34 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:31:55 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	average_color(int c1, int c2, unsigned char weight)
{
	int	alpha;
	int	r;
	int	g;
	int	b;

	alpha = ((unsigned char)(c1 >> 24)) * (weight);
	alpha += ((unsigned char)(c2 >> 24)) * (255 - weight);
	alpha /= 2 * 255;
	r = ((unsigned char)(c1 >> 16)) * (weight);
	r += ((unsigned char)(c2 >> 16)) * (255 - weight);
	r /= 2 * 255;
	g = ((unsigned char)(c1 >> 8)) * (weight);
	g += ((unsigned char)(c2 >> 8)) * (255 - weight);
	g /= 2 * 255;
	b = ((unsigned char)c1) * (weight);
	b += ((unsigned char)c2) * (255 - weight);
	b /= 2 * 255;
	return ((alpha << 24) | (r << 16) | ((g << 8) + b));
}

void	update_map_color(t_map *map, int c_min, int c_max)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->col_count)
		{
			if (map->data[i][j][cl] == 0)
				map->data[i][j][c] = average_color(c_min, c_max,
						(map->data[i][j][z] - map->z_min) / (map->z_max
							- map->z_min) * 255);
			j++;
		}
		i++;
	}
}

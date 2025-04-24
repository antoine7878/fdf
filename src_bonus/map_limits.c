/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_limits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:56:00 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:27:39 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <../include/fdf.h>
#include <math.h>

void	get_limits_z(t_map *map, int i, int j)
{
	map->z_min = fmin(map->data[i][j][z], map->z_min);
	map->z_max = fmax(map->data[i][j][z], map->z_max);
}

static void	get_limits_xy(t_map *map, int i, int j)
{
	map->x_min = fmin(map->data[i][j][x], map->x_min);
	map->x_max = fmax(map->data[i][j][x], map->x_max);
	map->y_min = fmin(map->data[i][j][y], map->y_min);
	map->y_max = fmax(map->data[i][j][y], map->y_max);
}

void	get_map_limits(t_map *map)
{
	map->x_max = map->data[0][0][x];
	map->x_min = map->data[0][0][x];
	map->y_max = map->data[0][0][y];
	map->y_min = map->data[0][0][y];
	iterijmap(map, get_limits_xy);
	map->tr_valx = distance(map->x_min, map->x_max) / 10;
	map->tr_valy = distance(map->y_min, map->y_max) / 10;
}

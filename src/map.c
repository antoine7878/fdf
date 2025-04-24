/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:13:50 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:38:03 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/include/libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void	center(t_fdf *fdf)
{
	get_map_limits(fdf->map);
	fdf->move->tr_x = (float)WIDTH / 2 - (fdf->map->x_max + fdf->map->x_min)
		/ 2;
	fdf->move->tr_y = (float)HEIGHT / 2 - (fdf->map->y_max + fdf->map->y_min)
		/ 2;
}

void	free_map(t_map *map)
{
	while ((map->row_count)--)
		free(map->data[map->row_count]);
	free(map->data);
}

void	iterijmap(t_map *map, void (*f)(t_map *, int, int))
{
	int	i;
	int	j;

	i = 0;
	while (i < map->row_count)
	{
		j = 0;
		while (j < map->col_count)
		{
			f(map, i, j);
			j++;
		}
		i++;
	}
}

int	parse_map_data(t_map *map, int fd)
{
	char	*line;

	map->row_count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map->data[map->row_count] = ft_split_coords(line, &map->col_count,
				map->row_count);
		free(line);
		if (!map->data[map->row_count])
			return (free_map(map), 0);
		map->row_count++;
	}
	get_map_limits(map);
	iterijmap(map, get_limits_z);
	return (1);
}

int	parse_args(char *file, t_map *map)
{
	int	fd;

	map->data = (t_point **)malloc(sizeof(t_point **) * (cout_line(file)));
	if (!map->data)
		return (0);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (free(map->data), 0);
	if (!parse_map_data(map, fd))
		return (0);
	close(fd);
	return (1);
}

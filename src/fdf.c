/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:06:39 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 10:33:31 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../minilibx-linux/mlx.h"
#include "../libft/include/libft.h"

static void	init(t_fdf *fdf, t_map *map, t_img *img, t_move *move)
{
	ft_bzero(fdf, sizeof(t_fdf));
	ft_bzero(map, sizeof(t_map));
	ft_bzero(img, sizeof(t_img));
	ft_bzero(move, sizeof(t_move));
	fdf->shift = 1;
	fdf->map = map;
	fdf->img = img;
	fdf->move = move;
	move->scaling = 2.5;
}

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	t_map	map;
	t_img	img;
	t_move	move;

	init(&fdf, &map, &img, &move);
	if (argc != 2)
		return (1);
	if (!parse_args(argv[1], fdf.map))
		return (2);
	if (!initilatize_fdf(&fdf, argv[1]))
		return (3);
	reset_iso(&fdf);
	put_map(&fdf);
	mlx_loop(fdf.mlx);
	close_all(&fdf);
	return (0);
}

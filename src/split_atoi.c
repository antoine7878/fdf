/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:00:01 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 14:03:43 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include "../libft/include/libft.h"
#include <stdio.h>
#include <stdlib.h>

static void	create_point(t_point pt, int row, int col, int nb)
{
	pt[x] = (float)col * 10;
	pt[y] = (float)row * 10;
	pt[z] = (float)nb;
	pt[cl] = 0;
}

static int	ft_atoi_hex(const char *str)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		ret = ret * 16 + ft_posinset(str[i], "0123456789ABCDEF");
		i++;
	}
	return (ret);
}

static void	add_color(t_point pt, const char **s)
{
	pt[c] = (float)ft_atoi_hex(*s + 3);
	pt[cl] = 1;
	*s += 9;
}

t_point	*ft_split_coords(char const *s, int *col_count, int row)
{
	t_point	*nbs;
	int		j;

	j = 0;
	*col_count = ft_countwords(s, " \n");
	nbs = (t_point *)malloc(sizeof(t_point) * *col_count);
	if (!nbs)
		return (NULL);
	while (*s)
	{
		while (*s && (*s == ' ' || *s == '\n'))
			s++;
		if (*s)
		{
			create_point(nbs[j], row, j, ft_atoi(s));
			while (*s && *s != ' ')
				s++;
			if (*s == ',')
				add_color(nbs[j], &s);
			j++;
		}
	}
	return (nbs);
}

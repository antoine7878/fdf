/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 20:04:36 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 18:31:59 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <X11/X.h>

void	rotate_x(t_point pt, float angle)
{
	float	yy;

	yy = pt[y];
	pt[y] = ft_cos(angle) * yy + ft_sin(angle) * pt[z];
	pt[z] = -ft_sin(angle) * yy + ft_cos(angle) * pt[z];
}

void	rotate_y(t_point pt, float angle)
{
	float	xx;

	xx = pt[x];
	pt[x] = ft_cos(angle) * xx - ft_sin(angle) * pt[z];
	pt[z] = ft_sin(angle) * xx + ft_cos(angle) * pt[z];
}

void	rotate_z(t_point pt, float angle)
{
	float	xx;

	xx = pt[x];
	pt[x] = ft_cos(angle) * xx + ft_sin(angle) * pt[y];
	pt[y] = -ft_sin(angle) * xx + ft_cos(angle) * pt[y];
}

void	translate_pt(t_point pt, float tr_x, float tr_y)
{
	pt[x] += tr_x;
	pt[y] += tr_y;
}

void	zoom_pt(t_point pt, float scaling)
{
	pt[x] *= scaling;
	pt[y] *= scaling;
}

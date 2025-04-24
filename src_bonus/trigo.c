/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trigo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:14:04 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 18:30:34 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <math.h>

float	ft_cos(float angle)
{
	static int		i = 0;
	static float	cos_table[TRIG_PREC];

	if (angle < 0)
		angle = -angle;
	if (i == 0)
	{
		while (i < TRIG_PREC)
		{
			cos_table[i] = cos(2.0 * M_PI * (float)i / (TRIG_PREC - 1));
			i++;
		}
	}
	return (cos_table[(int)(angle * TRIG_PREC / (2 * M_PI))]);
}

float	ft_sin(float angle)
{
	static int		i = 0;
	static float	sin_table[TRIG_PREC];

	if (angle < 0)
		angle = angle + 2 * M_PI;
	if (i == 0)
	{
		while (i < TRIG_PREC)
		{
			sin_table[i] = sin(2.0 * M_PI * (float)i / (TRIG_PREC - 1));
			i++;
		}
	}
	return (sin_table[(int)(angle * TRIG_PREC / (2 * M_PI))]);
}

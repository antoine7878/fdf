/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:56:15 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/14 09:56:42 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/_ft_printf.h"
#include <stdlib.h>

int	print_fmt(const char *fmt, t_conv *convs)
{
	int	count;

	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			if (convs->is_valid == 1)
			{
				count += print_conv(convs);
				fmt += convs->conv_len + 1;
				convs++;
				continue ;
			}
			convs++;
		}
		count += ft_putchar_count(*fmt);
		fmt++;
	}
	return (count);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_conv	*convs;
	int		count;

	if (!fmt)
		return (-1);
	convs = create_convs(fmt);
	if (!convs)
		return (-1);
	va_start(ap, fmt);
	parse_fmt(fmt, &ap, convs);
	count = print_fmt(fmt, convs);
	va_end(ap);
	free(convs);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:56:20 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/18 17:34:34 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/_ft_printf.h"
#include <unistd.h>

int	ft_putchar_count(int c)
{
	(void)!write(1, &c, 1);
	return (1);
}

int	ft_putpad_count(char c, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		ft_putchar_count(c);
	return (ft_max(0, len));
}

int	ft_putstr_count(char *str, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (str[i] && i < n)
		ft_putchar_count(str[i++]);
	return (ft_max(0, i));
}

int	ft_pnbc(long long n, char *base)
{
	int		base_len;
	int		i;
	int		j;
	char	nbs[25];

	if (n == 0)
		return (ft_putchar_count('0'));
	base_len = ft_strlen(base);
	i = 0;
	if (n < 0)
	{
		nbs[i++] = base[-(n % base_len)];
		n = n / base_len;
		n = -n;
	}
	while (n)
	{
		nbs[i++] = base[n % base_len];
		n = n / base_len;
	}
	j = i;
	while (i--)
		ft_putchar_count(nbs[i]);
	return (ft_max(0, j));
}

int	ft_punbc(unsigned long long n, char *base)
{
	unsigned int	base_len;
	int				count;

	count = 0;
	if (n == 0)
		return (ft_putchar_count('0'));
	base_len = ft_strlen(base);
	if (n >= base_len)
		count += ft_pnbc(n / base_len, base);
	count += ft_pnbc(n % base_len, base);
	return (count);
}

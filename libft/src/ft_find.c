/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:41:30 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/15 09:42:16 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	*ft_find(int *tab, int len, int x)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (tab[i] == x)
			return (tab + i);
		i++;
	}
	return (NULL);
}

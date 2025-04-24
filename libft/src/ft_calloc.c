/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:41:29 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/15 09:42:31 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*ret;
	size_t	len;

	len = nmemb * size;
	if (!len)
		return (NULL);
	ret = (char *)(malloc(len));
	if (!ret)
		return (NULL);
	ft_bzero(ret, len);
	return (ret);
}

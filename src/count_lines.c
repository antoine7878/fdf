/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cout_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-tell <ale-tell@42student.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:01:26 by ale-tell          #+#    #+#             */
/*   Updated: 2024/11/27 14:03:19 by ale-tell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int	cout_line(char *file)
{
	char	c;
	int		read_size;
	int		i;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	i = 0;
	while (1)
	{
		read_size = read(fd, &c, 1);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (-1);
		if (c == '\n')
			i++;
	}
	close(fd);
	return (i + 1);
}

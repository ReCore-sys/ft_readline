/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:37:49 by kshore            #+#    #+#             */
/*   Updated: 2023/10/16 17:30:11 by kshore           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <sys/errno.h>
#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

#include <fcntl.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;
	int			read_bytes;
	static int	last_nl;

	read_bytes = 0;
	if (!last_nl)
		last_nl = 0;
	line = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (1)
	{
		if (read_bytes >= last_nl)
		{
			if (read_bytes == BUFFER_SIZE)
				read_bytes = 0;
			if (read(fd, buf, 1) == -1 || errno == EAGAIN)
				return (line);
			if (buf[0] == '\n')
				break ;
			line[read_bytes] = *buf;
		}
		read_bytes++;
	}
	last_nl = read_bytes;
	line[read_bytes] = '\0';
	return (line);
}

int		main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}

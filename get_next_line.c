/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kshore <kshore@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:37:49 by kshore            #+#    #+#             */
/*   Updated: 2023/10/17 23:15:32 by kshore           ###   ########.fr       */
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
	static char	*nl_and_buf;
	long		i;
	char		temp[BUFFER_SIZE];
	char		*line;

	if (!nl_and_buf)
	{
		i = sizeof(long);
		nl_and_buf = malloc(BUFFER_SIZE + sizeof(long));
		while (read(fd, &temp, BUFFER_SIZE))
		{
			i += BUFFER_SIZE;
			nl_and_buf = ft_realloc(nl_and_buf, i + BUFFER_SIZE + sizeof(long));
		}
		nl_and_buf = ft_memcpy(&nl_and_buf[sizeof(long) * 2], temp, i);
		i = 0;
	}
	else
		i = nl_and_buf[0];
	line = malloc(1);
	while (nl_and_buf[i] && nl_and_buf[i] != '\n')
		line = append_and_extend(line, nl_and_buf[i++]);
	if (nl_and_buf[i] == '\n')
		line = append_and_extend(line, '\n');
	nl_and_buf[0] = ++i;
	return (line);
}

#if do_exe

int	main(void)
{
	int		fd;

	fd = open("test.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	return (0);
}

#endif
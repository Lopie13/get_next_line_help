/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:57:39 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/25 14:31:40 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE + 1];
	char		*result;
	int			i;

	i = 0;
	if (read(fd, 0, 0) < 0 || fd < 0 || BUFFER_SIZE < 1)
	{
		while (buff[i])
			buff[i++] = '\0';
		return (NULL);
	}
	result = NULL;
	while (buff[0] || read(fd, buff, BUFFER_SIZE) > 0)
	{
		result = ftstrjoin(result, buff);
		if (clean_buff(buff))
			break ;
	}
	return (result);
}

#include <fcntl.h>

int	main(void)
{
	int		fd;
	char	*line;
	int i = 1;
	printf("FILE 1:\n");
	fd = open("a.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("Line %d", i++);
		printf("-> %s", line);
		free(line);
		if (!line)
			break ;
	}
	close(fd);
	i = 1;
	printf("\nFILE 2:\n");
	fd = open("vb.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("Line %d", i++);
		printf("-> %s", line);
		free(line);
		if (!line)
			break ;
	}
	close(fd);
	i = 1;
	printf("\nCLOSED FILE:\n");
	fd = open("a.txt", O_RDONLY);
	close(fd);
	while (1)
{
	line = get_next_line(fd);
	printf("Line %d", i++);
	printf("-> %s", line);
	free(line);
	if (!line)
		break ;
}

return (0);
}
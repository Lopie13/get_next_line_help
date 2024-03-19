/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:00:55 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/19 14:05:47 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	clean_buff(char *buffer)
{
	int	this;

	this = 0;
	while (this < BUFFER_SIZE)
	{
		buffer[this] = 0;
		this++;
	}
}

void	buffer_neat(char *nlp, char *buf)
{
	if (nlp[1] == '\0')
		clean_buff(buf);
	else
		ft_strcpy(buf, nlp + 1);
}

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	char		*nullpntr;
	int			runs;

	if (read(fd, 0, 0) < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
	{
		clean_buff(buff[fd]);
		return (NULL);
	}
	result = NULL;
	runs = -1;
	while ((buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE)) && runs++ > -2)
	{
		nullpntr = ft_strchr(buff[fd], '\n');
		result = ftstrjoiner(result, buff[fd], runs);
		if (nullpntr)
		{
			buffer_neat(nullpntr, buff[fd]);
			break ;
		}
		else
			clean_buff (buff[fd]);
	}
	return (result);
}

/* #include <fcntl.h>

int	main(void)
{
int	fd1;
int	fd2;
char	*line;
char	*line2;
int i = 1;
int j = 1;
fd1 = open("a.txt", O_RDONLY);
fd2 = open("b.txt", O_RDONLY);
while (1)
{
	line = get_next_line(fd1);
	line2 = get_next_line(fd2);
	printf("1 - Line %d:\n", i++);
	printf("-> %s\n", line);
	printf("2 - Line %d:\n", j++);
	printf("-> %s\n", line2);
	free(line);
	free(line2);
	if (!line || !line2)
		break ;
}
close(fd1);
close(fd2);
return (0);
} */

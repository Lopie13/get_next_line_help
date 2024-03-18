/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:24:09 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/18 17:37:12 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

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
	static char	buff[BUFFER_SIZE + 1];
	char		*result;
	char		*nullpntr;
	int			runs;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
	{
		clean_buff(buff);
		return (NULL);
	}
	result = NULL;
	runs = -1;
	while ((buff[0] || read(fd, buff, BUFFER_SIZE)) && runs++ > -2)
	{
		nullpntr = ft_strchr(buff, '\n');
		result = ftstrjoiner(result, buff, runs);
		if (nullpntr)
		{
			buffer_neat(nullpntr, buff);
			break ;
		}
		else
			clean_buff (buff);
	}
	return (result);
}

/*#include <fcntl.h>

int	main(void)
{
int		fd;
char	*line;
int i = 1;
fd = open("a.txt", O_RDONLY);
while (1)
{
	line = get_next_line(fd);
	printf("Line %d:\n", i++);
	printf("-> %s", line);
	free(line);
	if (!line)
		break ;
}
close(fd);
return (0);
}*/

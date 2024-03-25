/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 11:46:45 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/25 14:46:53 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	buff[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*result;
	int			i;
	int			runs;

<<<<<<< HEAD
	i = 0;
	runs = -1;
	if (fd >= FOPEN_MAX || fd < 0 )
		return (NULL);
	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1)
=======
	if (read(fd, 0, 0) < 0 || fd >= FOPEN_MAX || BUFFER_SIZE < 1)
>>>>>>> 171791aef3cf323cbdaf64a82bf864154ef3e494
	{
		while (buff[fd][i])
			buff[fd][i++] = '\0';
		return (NULL);
	}
	result = NULL;
	while ((buff[fd][0] || read(fd, buff[fd], BUFFER_SIZE) > 0) && runs++ > -2)
	{
		result = ftstrjoiner(result, buff[fd], runs);
		if (clean_buff(buff[fd]))
			break ;
	}
	return (result);
}

#include <fcntl.h>

int	main(void)
{
int	fd1;
int	fd2;
char	*line;
char	*line2;
int i = 1;
int j = 1;
fd1 = open("a.txt", O_RDONLY);
fd2 = open("-b.txt", O_RDONLY);
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
<<<<<<< HEAD
}
=======
} */
>>>>>>> 171791aef3cf323cbdaf64a82bf864154ef3e494

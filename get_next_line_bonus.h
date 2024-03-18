/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:00:59 by mmata-al          #+#    #+#             */
/*   Updated: 2024/03/14 12:02:43 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

size_t	ft_strlenn(const char *s);
void	ft_strcpy(char *dest, const char *src);
char	*get_next_line(int fd);
void	clean_buff(char *buffer);
void	buffer_neat(char *nlp, char *buf);
char	*ft_strchr(const char *s, int c);
char	*ftstrjoiner(char *s1, char *s2, int runs);

#endif
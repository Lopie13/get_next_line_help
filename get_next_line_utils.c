/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:24:13 by mmata-al          #+#    #+#             */
/*   Updated: 2023/12/06 20:24:03 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)c)
			return (str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)c)
		return (str);
	return (NULL);
}

void	ft_strcpy(char *dest, const char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

size_t	ft_strlenn(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*ftstrjoiner(char *s1, char *s2, int runs)
{
	char	*str;
	int		i;
	int		j;

	if (s1 == NULL)
		s1 = "";
	str = (char *)malloc(ft_strlenn(s1) + ft_strlenn(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 != NULL && s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2 != NULL && s2[i] != '\0')
	{
		str[j++] = s2[i++];
		if (s2[i - 1] == '\n')
			break ;
	}
	if (runs > 0)
		free(s1);
	str[j] = '\0';
	return (str);
}

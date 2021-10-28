/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:13 by idhiba            #+#    #+#             */
/*   Updated: 2020/09/24 14:45:39 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>

char	*ft_strdup(char *s)
{
	int		i;
	char	*str;
	int		e;

	e = 0;
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(str = malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	while (e < i)
	{
		str[e] = s[e];
		e++;
	}
	str[e] = '\0';
	return (str);
}

int		ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

int		read_line(int fd, char **dest)
{
	char	*buff;
	int		ret;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while (!ft_strchr(*dest, '\n') && (ret = read(fd, buff, BUFFER_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buff[ret] = '\0';
		if ((*dest = ft_strjoin_free(*dest, buff, 1)) == NULL)
			return (-1);
	}
	free(buff);
	return (ret);
}

char	*ft_no_leaks(char *dest, int i)
{
	char	*tmp;

	if (dest[i] == '\n')
	{
		tmp = dest;
		dest = ft_strdup(tmp + i + 1);
		free(tmp);
	}
	else
	{
		free(dest);
		dest = NULL;
	}
	return (dest);
}

int		get_next_line(int fd, char **line)
{
	static char	*dest;
	int			ret;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || !line || fd < 0)
		return (-1);
	if (!(dest))
		dest = ft_calloc(1, 1);
	if ((ret = read_line(fd, &dest)) == -1)
		return (-1);
	while (dest[i] != '\n' && dest[i] != '\0')
		i++;
	*line = ft_substr(dest, 0, i);
	dest = ft_no_leaks(dest, i);
	if (!dest && !ret)
	{
		free(dest);
		return (0);
	}
	return (1);
}

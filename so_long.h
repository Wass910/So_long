/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idhiba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 18:17:19 by idhiba            #+#    #+#             */
/*   Updated: 2019/11/17 18:17:21 by idhiba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/uio.h>

typedef struct s_CheckMap
{
	int	    collectible;
	int     appears;
    int     exit;
}	t_CheckMap;

int		get_next_line(int fd, char **line);
char	*ft_strjoin_free(char *s1, char *s2, int f);
char	*ft_strchr(char *s, int c);
void	*ft_calloc(int count, int size);
char	*ft_substr(char *s, int start, int len);
char	*ft_strdup(char *s);
int		ft_strlen(char *s);
int		ft_count(char *s1, char *s2);
int		read_line(int fd, char **dest);
char	*ft_no_leaks(char *dest, int i);
char		*ft_strcat(char *dest, char *src);
char			**ft_split(char  *s, char c);

#endif

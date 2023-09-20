/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:05:21 by amaso             #+#    #+#             */
/*   Updated: 2022/02/07 22:54:41 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<unistd.h>
# include<stdlib.h>
# include<stdio.h>
# include<string.h>
# include <fcntl.h>

int		get_ft_strlen(char *s);
int		get_ft_strlcpy(char *dst, char *src, int dstsize);
char	*get_nl(char *beenread, int i);
int		find_nl(char *beenread);
char	*setbeenread(char *beenread);

char	*get_ft_strjoin(char *s1, char *s2, int size);
char	*store_extra(char *beenread, int i);
char	*set_toread(char *beenread, char *toread);
int		ft_cycle(char **beenread, char *toread, int fd, int rd);
char	*get_next_line(int fd);

#endif

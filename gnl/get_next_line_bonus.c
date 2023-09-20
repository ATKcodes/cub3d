/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 17:59:06 by amaso             #+#    #+#             */
/*   Updated: 2022/02/01 17:59:28 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_ft_strjoin(char *s1, char *s2, int size)
{
	char	*str;
	int		i;
	int		y;

	y = 0;
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*str) * (size + 1));
	if (!str)
		return (NULL);
	get_ft_strlcpy(str, s1, (size + 1));
	i = get_ft_strlen(str);
	if ((size + 1) > i)
	{
		while (s2[y] != '\0' && i < ((size + 1) - 1))
		{
			str[i] = s2[y];
			y++;
			i++;
		}
		str[i] = '\0';
	}
	free(s1);
	return (str);
}

//stores the extra characters that have been read from the program in beenread.
char	*store_extra(char *beenread, int i)
{
	int		d;
	int		c;
	char	*temp;

	c = 0;
	d = (int)get_ft_strlen(beenread) - i;
	temp = (char *) malloc (sizeof(char) * d + 1);
	if (temp == NULL)
		return (NULL);
	while (c < d)
	{
		temp[c] = beenread[c + i];
		c++;
	}
	temp[c] = 0;
	free (beenread);
	beenread = (char *) malloc (sizeof(char) * get_ft_strlen(temp) + 1);
	while (!beenread)
		return (NULL);
	get_ft_strlcpy(beenread, temp, (get_ft_strlen(temp) + 1));
	beenread[get_ft_strlen(temp)] = 0;
	free (temp);
	temp = NULL;
	return (beenread);
}

char	*set_toread(char *beenread, char *toread)
{
	int	i;

	i = -1;
	i = find_nl(beenread);
	free (toread);
	toread = NULL;
	if (i >= 0)
		toread = get_nl(beenread, i + 1);
	else
	{
		if (beenread && get_ft_strlen(beenread) > 0)
			toread = get_nl(beenread, get_ft_strlen(beenread));
	}
	return (toread);
}

int	ft_cycle(char **beenread, char *toread, int fd, int rd)
{
	int	res;
	int	size;

	if (*beenread)
		size = get_ft_strlen(*beenread);
	else
	{
		size = 0;
		*beenread = setbeenread(*beenread);
	}
	while (rd > 0)
	{
		size = size + rd;
		toread[BUFFER_SIZE] = 0;
		*beenread = get_ft_strjoin(*beenread, toread, size);
		res = find_nl(*beenread);
		if (res != -1)
			break ;
		rd = read (fd, toread, BUFFER_SIZE);
		if (rd < 0)
			return (0);
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*beenread[1024];
	char		*toread;
	int			rd;

	if (fd < 0 || BUFFER_SIZE < 0 || fd > 1024)
		return (0);
	toread = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	if (!toread)
		return (NULL);
	rd = read(fd, toread, BUFFER_SIZE);
	if (rd < 0)
		free(toread);
	if (rd < 0 || !ft_cycle(&beenread[fd], toread, fd, rd))
		return (NULL);
	toread = set_toread(beenread[fd], toread);
	if (find_nl(beenread[fd]) != -1)
		beenread[fd] = store_extra(beenread[fd], find_nl(beenread[fd]) + 1);
	else
	{
		free(beenread[fd]);
		beenread[fd] = NULL;
	}
	return (toread);
}

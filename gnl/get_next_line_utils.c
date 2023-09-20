/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 16:04:56 by amaso             #+#    #+#             */
/*   Updated: 2022/01/30 16:06:02 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	get_ft_strlen(char *s)
{
	int	counter;

	counter = 0;
	while (s[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

int	get_ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	count = get_ft_strlen(src);
	if (!dst)
		return (count);
	if (dstsize != 0)
	{
		while (src[index] != '\0' && index < (dstsize - 1))
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (count);
}

//finds the line to print and returns it.
char	*get_nl(char *beenread, int i)
{
	int		d;
	char	*new_line;

	new_line = malloc (sizeof(char) * (i + 1));
	if (!new_line)
		return (NULL);
	d = 0;
	get_ft_strlcpy(new_line, beenread, i + 1);
	return (new_line);
}

//searches for a nl and returns the position.
int	find_nl(char *beenread)
{
	int	i;

	i = 0;
	while (beenread[i] != 0)
	{
		if (beenread[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*setbeenread(char *beenread)
{
	if (!beenread)
	{
		beenread = malloc (sizeof(char) * (1));
		beenread[0] = 0;
		if (!beenread)
			return (0);
	}
	return (beenread);
}

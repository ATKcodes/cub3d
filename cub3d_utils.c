/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:12:09 by amaso             #+#    #+#             */
/*   Updated: 2023/10/14 20:12:13 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_gnllen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i;
	int	a;

	i = -1;
	while (str[++i])
		a += write(1, &str[i], 1);
}

int	ft_is_comma_num(int c, t_pars *pars)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else if (c == 44 && pars->comma_counter < 2)
	{
		pars->comma_counter++;
		return (1);
	}
	else
		return (0);
}

void	*ft_calloc(size_t nmeb, size_t size)
{
	void	*a;

	a = malloc (size * nmeb);
	if (a == NULL)
		return (a);
	ft_memset(a, 0, (size * nmeb));
	return (a);
}

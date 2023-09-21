/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:48 by amaso             #+#    #+#             */
/*   Updated: 2023/09/20 19:57:51 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_pars *pars)
{
	int	i = -1;

	if(get_next_line(pars->fd) == NULL)
		ft_error("File isn't readable\n");
	while ()
}

int	main(int argc, char *argv[])
{
	t_pars	pars;
	if (argc != 2)
		ft_error("Invalid arguments\n");
	if (strlen(argv(1)) < 5 && argv[1][ft_strlen(argv(1)) - 4] != '.'
			&& argv[1][ft_strlen(argv(1)) - 3] != 'c'
				&& argv[1][strlen(argv(1)) - 2] != 'u'
					&& argv[1][strlen(argv(1)) - 1] != 'b')
		ft_error("Invalid file extension\n");
	pars.fd = open(argv(1))
	if (pars.fd == -1)
		ft_error("Can't open file\n");
	parsing(&pars);
}

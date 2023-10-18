/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_gather.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:27:28 by amaso             #+#    #+#             */
/*   Updated: 2023/10/14 20:27:32 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_info(t_pars *pars)
{
	pars->info.count_info = 0;
	// free_matrix (pars);
	pars->gnl = get_next_line(pars->fd);
	// free (pars->gnl);
	// free_matrix (pars);
	while (pars->gnl && pars->info.count_info < 6
		&& pars->gnl[0] != ' ' && pars->gnl[0] != '1')
	{
		if (ft_gnllen(pars->gnl) > 0 && ft_gnllen(pars->gnl) < 6)
			ft_error("Invalid parameters");
		if (ft_gnllen(pars->gnl) >= 6)
		{
			if (pars->gnl[0] == 'N' && pars->gnl[1] == 'O'
				&& pars->gnl[2] == ' ')
				save_north(pars);
			else if (pars->gnl[0] == 'S' && pars->gnl[1] == 'O'
				&& pars->gnl[2] == ' ')
				save_south(pars);
			else if (pars->gnl[0] == 'E' && pars->gnl[1] == 'A'
				&& pars->gnl[2] == ' ')
				save_east(pars);
			else if (pars->gnl[0] == 'W' && pars->gnl[1] == 'E'
				&& pars->gnl[2] == ' ')
				save_west(pars);
			else if (pars->gnl[0] == 'C' && pars->gnl[1] == ' ')
				save_background(pars);
			else if (pars->gnl[0] == 'F' && pars->gnl[1] == ' ')
				save_background(pars);
			else
			{
				ft_error("Invalid parameteeers");
				free(pars->gnl);
				free_matrix(pars);
			}
		}
		free(pars->gnl);
		pars->gnl = get_next_line(pars->fd);
	}
	free(pars->gnl);
	if (pars->info.count_info != 6)
	{
		ft_error("Wrong parameteeers1\n");
		free_matrix(pars);
	}
}

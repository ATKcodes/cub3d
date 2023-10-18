/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:45:16 by amaso             #+#    #+#             */
/*   Updated: 2023/10/18 20:45:18 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_north(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.no.flag != 0)
	{
		ft_error("Wrong parameters\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	pars->info.no.flag++;
	pars->info.no.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.no.addr[i] = pars->gnl[i + 3];
	pars->info.no.addr[i] = '\0';
	fd = open(pars->info.no.addr, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Wrong address\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	close(fd);
	pars->info.count_info++;
}

void	save_south(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.so.flag != 0)
	{
		ft_error("Wrong parameters\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	pars->info.so.flag++;
	pars->info.so.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.so.addr[i] = pars->gnl[i + 3];
	pars->info.so.addr[i] = '\0';
	fd = open(pars->info.so.addr, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Wrong address\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	close(fd);
	pars->info.count_info++;
}

void	save_east(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.ea.flag != 0)
	{
		ft_error("Wrong parameters\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	pars->info.ea.flag++;
	pars->info.ea.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.ea.addr[i] = pars->gnl[i + 3];
	pars->info.ea.addr[i] = '\0';
	fd = open(pars->info.ea.addr, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Wrong address\n");
		free(pars->gnl);
		free_matrix(pars);
	}
	close(fd);
	pars->info.count_info++;
}

void	save_west(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.we.flag != 0)
	{
		ft_error("Wrong parameters\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	pars->info.we.flag++;
	pars->info.we.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.we.addr[i] = pars->gnl[i + 3];
	pars->info.we.addr[i] = '\0';
	fd = open(pars->info.we.addr, O_RDONLY);
	if (fd == -1)
	{
		ft_error("Wrong address\n");
		free (pars->gnl);
		free_matrix(pars);
	}
	close(fd);
	pars->info.count_info++;
}

void	init_flags(t_pars *pars)
{
	pars->info.foundp = 0;
	pars->info.no.flag = 0;
	pars->info.ea.flag = 0;
	pars->info.we.flag = 0;
	pars->info.so.flag = 0;
	pars->info.ceiling.flag = 0;
	pars->info.floor.flag = 0;
	pars->info.floor.red = -1;
	pars->info.floor.green = -1;
	pars->info.floor.blue = -1;
	pars->info.ceiling.red = -1;
	pars->info.ceiling.green = -1;
	pars->info.ceiling.blue = -1;
}

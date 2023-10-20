/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:26:26 by amaso             #+#    #+#             */
/*   Updated: 2023/10/14 20:26:30 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Free all to close the game with exit(0)
void	free_all(t_pars	*pars)
{
	int	d;

	d = 0;
	free_images(pars);
	if (pars->info.no.flag == 1)
		free(pars->info.no.addr);
	if (pars->info.so.flag == 1)
		free(pars->info.so.addr);
	if (pars->info.ea.flag == 1)
		free(pars->info.ea.addr);
	if (pars->info.we.flag == 1)
		free(pars->info.we.addr);
	while (d < pars->rows)
		free(pars->matrix[d++]);
	free(pars->matrix);
	pars->matrix = NULL;
	mlx_destroy_display(pars->mlx.mlx_init);
	free (pars->mlx.mlx_init);
	exit(0);
}

//Free to free everything but with exit(1)
void	free_xpm(t_pars *pars)
{
	free_images(pars);
	free_matrix(pars);
}

//Freeing images
void	free_images(t_pars *pars)
{
	mlx_destroy_image(pars->mlx.mlx_init, pars->mlx.img.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.no.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.so.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.ea.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.we.img);
	mlx_destroy_window(pars->mlx.mlx_init, pars->mlx.mlx_win);
}

//Freeing the matrix with the map
void	free_matrix(t_pars	*pars)
{
	int	d;

	d = 0;
	if (pars->info.no.flag == 1)
		free(pars->info.no.addr);
	if (pars->info.so.flag == 1)
		free(pars->info.so.addr);
	if (pars->info.ea.flag == 1)
		free(pars->info.ea.addr);
	if (pars->info.we.flag == 1)
		free(pars->info.we.addr);
	while (d < pars->rows)
		free(pars->matrix[d++]);
	free(pars->matrix);
	pars->matrix = NULL;
	mlx_destroy_display(pars->mlx.mlx_init);
	free (pars->mlx.mlx_init);
	exit(1);
}

//Freeing everything without the rows of the matrix
void	free_info(t_pars *pars)
{
	while (pars->gnl)
	{
		free(pars->gnl);
		pars->gnl = get_next_line(pars->fd);
	}
	close (pars->fd);
	if (pars->info.no.flag == 1)
		free(pars->info.no.addr);
	if (pars->info.so.flag == 1)
		free(pars->info.so.addr);
	if (pars->info.ea.flag == 1)
		free(pars->info.ea.addr);
	if (pars->info.we.flag == 1)
		free(pars->info.we.addr);
	free(pars->matrix);
	mlx_destroy_display(pars->mlx.mlx_init);
	free (pars->mlx.mlx_init);
	exit(1);
}

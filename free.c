#include "cub3d.h"

void	free_all(t_pars	*pars)
{
	int	d;

	d = 0;
	while (d < pars->rows)
	{
		free(pars->matrix[d++]);
	}
	free(pars->matrix);
		free(pars->info.NO.addr);
	free(pars->info.SO.addr);
	free(pars->info.EA.addr);
	free(pars->info.WE.addr);
	free_images(pars);
	exit(0);

}
void	free_images (t_pars *pars)
{
	mlx_destroy_window(pars->mlx.mlx_init, pars->mlx.mlx_win);
	mlx_destroy_image(pars->mlx.mlx_init, pars->mlx.img.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.NO.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.SO.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.EA.img);
	mlx_destroy_image(pars->mlx.mlx_init, pars->info.WE.img);
	
}
void	free_matrix(t_pars	*pars)
{
	int	d;

	d = 0;
	free(pars->info.NO.addr);
	free(pars->info.SO.addr);
	free(pars->info.EA.addr);
	free(pars->info.WE.addr);
	while (d < pars->rows)
	{
		free(pars->matrix[d++]);
	}
	free(pars->matrix);
	exit(0);
}

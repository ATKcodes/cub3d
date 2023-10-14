#include "cub3d.h"

void	xpm_init(t_pars *pars)
{
	int	width;
	int	height;
		
	pars->info.so.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
							pars->info.so.addr, &width, &height);
	free (pars->info.so.addr);
	pars->info.so.flag--;
	pars->info.so.addr = mlx_get_data_addr(pars->info.so.img, &pars->info.so.bits_per_pixel, &pars->info.so.line_length, &pars->info.so.endian);
	if (!pars->info.so.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
	pars->info.no.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
							pars->info.no.addr, &width, &height);
	free (pars->info.no.addr);
	pars->info.no.flag--;
	pars->info.no.addr = mlx_get_data_addr(pars->info.no.img, &pars->info.no.bits_per_pixel, &pars->info.no.line_length, &pars->info.no.endian);
	if (!pars->info.no.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
	xpm_init2(pars);
}

void	xpm_init2(t_pars *pars)
{
	int	width;
	int	height;
	pars->info.ea.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
			pars->info.ea.addr, &width, &height);
	free (pars->info.ea.addr);
	pars->info.ea.flag--;
	pars->info.ea.addr = mlx_get_data_addr(pars->info.ea.img, &pars->info.ea.bits_per_pixel, &pars->info.ea.line_length, &pars->info.ea.endian);
	if (!pars->info.ea.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
	pars->info.we.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
							pars->info.we.addr, &width, &height);
	free (pars->info.we.addr);
	pars->info.we.flag--;
	if (!pars->info.we.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
	pars->info.we.addr = mlx_get_data_addr(pars->info.we.img, &pars->info.we.bits_per_pixel, &pars->info.we.line_length, &pars->info.we.endian);
}
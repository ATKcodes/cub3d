#include "cub3d.h"

    void    xpm_init(t_pars *pars)
{
    int		width;
	int		height;
			
    pars->info.SO.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.SO.addr, &width, &height);
	free (pars->info.SO.addr);
    pars->info.SO.addr = mlx_get_data_addr(pars->info.SO.img, &pars->info.SO.bits_per_pixel, &pars->info.SO.line_length, &pars->info.SO.endian);
	if (!pars->info.SO.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}

        pars->info.NO.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.NO.addr, &width, &height);
	free (pars->info.NO.addr);
    pars->info.NO.addr = mlx_get_data_addr(pars->info.NO.img, &pars->info.NO.bits_per_pixel, &pars->info.NO.line_length, &pars->info.NO.endian);
	if (!pars->info.NO.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
        pars->info.EA.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.EA.addr, &width, &height);
	free (pars->info.EA.addr);
    pars->info.EA.addr = mlx_get_data_addr(pars->info.EA.img, &pars->info.EA.bits_per_pixel, &pars->info.EA.line_length, &pars->info.EA.endian);
	if (!pars->info.EA.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
    pars->info.WE.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                        pars->info.WE.addr, &width, &height);
	free (pars->info.WE.addr);
	if (!pars->info.WE.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
		free_all(pars);
	}
    pars->info.WE.addr = mlx_get_data_addr(pars->info.WE.img, &pars->info.WE.bits_per_pixel, &pars->info.WE.line_length, &pars->info.WE.endian);
}

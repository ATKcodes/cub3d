#include "cub3d.h"

    void    xpm_init(t_pars *pars)
{
    int		width;
	int		height;

    pars->info.SO.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.SO.addr, &width, &height);
    pars->info.SO.addr = mlx_get_data_addr(pars->info.SO.img, &pars->info.SO.bits_per_pixel, &pars->info.SO.line_length, &pars->info.SO.endian);
	if (pars->info.SO.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
	//	close_game(cub, "\033[1;31Path error");
	}

        pars->info.NO.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.NO.addr, &width, &height);
    pars->info.NO.addr = mlx_get_data_addr(pars->info.NO.img, &pars->info.NO.bits_per_pixel, &pars->info.NO.line_length, &pars->info.NO.endian);
	if (pars->info.NO.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
	//	close_game(cub, "\033[1;31Path error");
	}
        pars->info.EA.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                            pars->info.EA.addr, &width, &height);
    pars->info.EA.addr = mlx_get_data_addr(pars->info.EA.img, &pars->info.EA.bits_per_pixel, &pars->info.EA.line_length, &pars->info.EA.endian);
	if (pars->info.EA.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
	//	close_game(cub, "\033[1;31Path error");
	}
    pars->info.WE.img = mlx_xpm_file_to_image(pars->mlx.mlx_init,
                        pars->info.WE.addr, &width, &height);
    pars->info.WE.addr = mlx_get_data_addr(pars->info.WE.img, &pars->info.WE.bits_per_pixel, &pars->info.WE.line_length, &pars->info.WE.endian);
	if (pars->info.WE.img)
	{
		ft_error("XPM Error : check IMG_PATH or fileName");
	//	close_game(cub, "\033[1;31Path error");
	}
}
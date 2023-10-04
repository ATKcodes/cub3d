#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void    new_window(t_pars *pars)
{
    pars->mlx.mlx_init = mlx_init();
    pars->mlx.mlx_win = mlx_new_window(pars->mlx.mlx_init, 1920, 1080, "cub3d");
	rgb_to_hex(pars);
    mlx_loop(pars->mlx.mlx_init);
}

void    rgb_to_hex(t_pars *pars)
{
	int	y;
	int	x;

	y = -1;
	pars->mlx.img.img = mlx_new_image(pars->mlx.mlx_init, 1920, 1080);
	pars->mlx.img.addr = mlx_get_data_addr(pars->mlx.img.img, &pars->mlx.img.bits_per_pixel,
							&pars->mlx.img.line_length, &pars->mlx.img.endian);
    pars->info.ceiling.hex = pars->info.ceiling.blue + (pars->info.ceiling.green << 8) + (pars->info.ceiling.red << 16);
    pars->info.floor.hex = pars->info.floor.blue + (pars->info.floor.green << 8) + (pars->info.floor.red << 16);
	while (++y < 1080)
	{
		x = -1;
		while (++x < 1920)
		{
			if (y < 1080/2)
				my_mlx_pixel_put(&pars->mlx.img, x, y, pars->info.ceiling.hex);
			else
				my_mlx_pixel_put(&pars->mlx.img, x, y, pars->info.floor.hex);
		}
	}
	mlx_put_image_to_window(pars->mlx.mlx_init, pars->mlx.mlx_win, pars->mlx.img.img, 0, 0);
} 

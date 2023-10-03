#include "cub3d.h"

void    new_window(t_pars *pars)
{
    pars->mlx.mlx_init = mlx_init();
    pars->mlx.mlx_win = mlx_new_window(pars->mlx.mlx_init, 1920, 1080, "cub3d");
    mlx_loop(pars->mlx.mlx_init);
}

void    rgb_to_hex(t_pars *pars)
{
    pars.info.ceiling.hex = pars->info.ceiling.blue + pars.info.ceiling.green << 8 + pars.info.ceiling.red << 16;
    pars.info.floor.hex = pars->info.floor.blue + pars.info.floor.green << 8 + pars.info.floor.red << 16;
} 
void    set_background(t_pars *pars)
{     
}
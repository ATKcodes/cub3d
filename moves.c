#include "cub3d.h"
int moves_loop(t_pars *pars, int key)
{
    if (key == 115)
	{
		pars->player.x -= pars->player.dir_x * MOVESTEP;
		pars->player.y -= pars->player.dir_y * MOVESTEP;
	}
	else if (key == 119)
	{
		pars->player.x += pars->player.dir_x * MOVESTEP;
		pars->player.y += pars->player.dir_y * MOVESTEP;
	}
	else if (key == 97)
	{
		pars->player.x += pars->player.dir_y * MOVESTEP;
		pars->player.y -= pars->player.dir_x * MOVESTEP;
	}
	else if (key == 100)
	{
		pars->player.x -= pars->player.dir_y * MOVESTEP;
		pars->player.y += pars->player.dir_x * MOVESTEP;
	}
	// if (key == 124 || key == 123)
	// 	rotate_player(cub, key, THREE_DEG);

	//mlx_clear_window(pars->mlx.mlx_init, pars->mlx.mlx_win);	
	// new_window(pars);
	rgb_to_hex(pars);
	draw_game(pars);
    return(0);

}

int moves(int key, t_pars *pars)
{
    printf("ciaoo %d\n", key);
    if(key == 65307)
    {
        ft_error("premuto esc"); //da cambiare
        exit(1);
    }
     moves_loop(pars, key);
    return(1);
}


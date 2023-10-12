#include "cub3d.h"
int moves_loop(t_pars *pars, int key)
{
    if (key == 1)
	{
		pars->player.x -= pars->player.dir_x * MOVESTEP;
		pars->player.y -= pars->player.dir_y * MOVESTEP;
	}
	else if (key == 13)
	{
		pars->player.x += pars->player.dir_x * MOVESTEP;
		pars->player.y += pars->player.dir_y * MOVESTEP;
	}
	else if (key == 0)
	{
		pars->player.x += pars->player.dir_y * MOVESTEP;
		pars->player.y -= pars->player.dir_x * MOVESTEP;
	}
	else if (key == 2)
	{
		pars->player.x -= pars->player.dir_y * MOVESTEP;
		pars->player.y += pars->player.dir_x * MOVESTEP;
	}
	// if (key == 124 || key == 123)
	// 	rotate_player(cub, key, THREE_DEG);
    draw_game(pars);
    return(0);

}

int moves(int key, t_pars *pars)
{
    printf("ciaoo");
    if(key == 53)
    {
        ft_error("premuto esc"); //da cambiare
        exit(1);
    }
     moves_loop(pars, key);
    return(0);
}


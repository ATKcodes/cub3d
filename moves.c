#include "cub3d.h"

void	moves_loop(t_pars *pars, int key)
{
	if (check_wall_collision(pars, key))
		return ;
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
	moves_loop2(pars, key);
}

void	moves_loop2(t_pars *pars, int key)
{
	if (key == 65361 || key == 65363)
 		rotate_player(pars, key, ROTATE_G);
	rgb_to_hex(pars);
	draw_game(pars);
}

int moves(int key, t_pars *pars)
{
    printf("ciaoo %d\n", key);
    if(key == 65307)
    {
		free_all(pars);
    }
    moves_loop(pars, key);
    return(1);
}

void	update_player_position(t_pars *temp, int key)
{
  if (key == 115)
	{
		temp->player.x -= temp->player.dir_x * MOVESTEP;
		temp->player.y -= temp->player.dir_y * MOVESTEP;
	}
	else if (key == 119)
	{
		temp->player.x += temp->player.dir_x * MOVESTEP;
		temp->player.y += temp->player.dir_y * MOVESTEP;
	}
	else if (key == 97)
	{
		temp->player.x += temp->player.dir_y * MOVESTEP;
		temp->player.y -= temp->player.dir_x * MOVESTEP;
	}
	else if (key == 100)
	{
		temp->player.x -= temp->player.dir_y * MOVESTEP;
		temp->player.y += temp->player.dir_x * MOVESTEP;
	}
}

int	check_wall_collision(t_pars *pars, int key)
{
	t_pars		temp;
	t_ray		ray;
	double		camera_x;
	int			x;

	temp = *pars;
	update_player_position(&temp, key);
	if (key == 65361 || key == 65363)
 		rotate_player(&temp, key, ROTATE_G);
	if (pars->matrix[(int)temp.player.y][(int)temp.player.x] == '1')
		return (1);
	set_plane(&temp);
	x = 0;
	while (x < WIN_SIZE_W)
	{
		camera_x = 2 * x / (double)WIN_SIZE_W - 1;
		ray = raycast(&temp, camera_x);
		if (ray.perp_wall_dist < MOVESTEP)
			return (1);
		x++;
	}
	return (0);
}

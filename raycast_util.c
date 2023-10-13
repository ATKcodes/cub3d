#include "cub3d.h"

void	set_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

void	set_delta_dist(t_ray *ray)
{
	if (ray->ray_dir.y == 0)
	{
		ray->delta_dist.x = 0;
	}
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
	{
		ray->delta_dist.y = 0;
	}
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void	set_side_dist(t_ray *ray, t_pars *pars)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pars->player.x - (double)ray->map_x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map_x + 1.0 - pars->player.x) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pars->player.y - (double)ray->map_y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_y + 1.0 - pars->player.y) * ray->delta_dist.y;
}

void	rotate_player(t_pars *pars, int key, double angle)
{
	double old_dirx;
	double old_diry;
	double old_planex;
	double old_planey;
	if(key == 65361)
		angle *= -1;
	old_dirx = pars->player.dir_x;
	old_diry = pars->player.dir_y;
	old_planex = pars->player.plane.x;
	old_planey = pars->player.plane.y;
	pars->player.dir_x = old_dirx * cos(angle) - old_diry * sin(angle);
	pars->player.dir_y = old_dirx * sin(angle) + old_diry * cos(angle);
	pars->player.plane.x = old_planex * cos(angle) - old_planey * sin(angle);
	pars->player.plane.y = old_planex * sin(angle) + old_planey * cos(angle);
}

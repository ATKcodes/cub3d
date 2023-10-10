#include "cub3d.h"

void	set_ray(t_pars *pars, t_ray *ray, double camera_x)
{
	ray->ray_dir.x = pars->player.dir_x + pars->player.plane.x * camera_x;
	ray->ray_dir.y = pars->player.dir_y + pars->player.plane.y * camera_x;
	ray->map_x = (int)pars->player.x;
	ray->map_y = (int)pars->player.y;
	set_delta_dist(ray);
	set_step(ray);
	set_side_dist(ray, pars);
}

void	update_ray(t_ray *ray, int axis)
{
	if (axis == 0)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = 0;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = 1;
	}
}

void	set_perp_wall_dist(t_ray *ray, t_pars *pars)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - pars->player.x + (1 - ray->step_x) / 2.0)
			/ ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - pars->player.y + (1 - ray->step_y) / 2.0)
			/ ray->ray_dir.y;
}

t_ray	raycast(t_pars *pars, double camera_x)
{
	t_ray	ray;
	int		hit;

	hit = 0;
	set_ray(pars, &ray, camera_x);
	while (hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
			update_ray(&ray, 0);
		else if (ray.side_dist.x > ray.side_dist.y)
			update_ray(&ray, 1);
		else
		{
			update_ray(&ray, 0);
			update_ray(&ray, 1);
		}
		if (pars->matrix[ray.map_y][ray.map_x] == '1')
			hit = 1;
	}
	set_perp_wall_dist(&ray, pars);
	return (ray);
}

void	draw_game(t_pars *pars)
{
	int		x;
	t_ray	ray;
	double	camera_x;

	x = 0;
	while (x < 1920)
	{
		camera_x = 2 * x / (double)1920 - 1;
		ray = raycast(pars, camera_x);
		//draw_wall(pars, &ray, x);
		x++;
	}
	mlx_put_image_to_window(pars->mlx.mlx_init, pars->mlx.mlx_win,
		pars->mlx.img.img, 0, 0);
}

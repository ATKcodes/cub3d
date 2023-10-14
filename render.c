#include "cub3d.h"
int	get_texture_scaled_x(t_pars *pars, t_ray *ray)
{
	double	wall_x;
	int		texture_x;

	if (ray->side == 0)
		wall_x = pars->player.y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = pars->player.x + ray->perp_wall_dist * ray->ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	texture_x = (int)(wall_x * (double)TILE_SIZE);
	if (ray->side == 0 && ray->ray_dir.x < 0)
		texture_x = TILE_SIZE - texture_x - 1;
	if (ray->side == 1 && ray->ray_dir.y > 0)
		texture_x = TILE_SIZE - texture_x - 1;
	return (texture_x);
}

unsigned int	get_img_color(t_data *data, int x, int y)
{
	int	color_byte;
	int	pixel;

	color_byte = data->bits_per_pixel / 8;
	pixel = (y * data->line_length) / color_byte + x;
	return (*((unsigned int *)data->addr + pixel));
}

t_render_info	get_render_info(t_ray *ray, t_pars *pars)
{
	t_render_info	render_info;

	render_info.line_height = (int)(WIN_SIZE_H / ray->perp_wall_dist);
	render_info.ratio = (double)TILE_SIZE / render_info.line_height;
	render_info.start_y = (WIN_SIZE_H / 2) - (render_info.line_height / 2);
	render_info.end_y = (WIN_SIZE_H / 2) + (render_info.line_height / 2);
	if (render_info.start_y < 0)
		render_info.start_y = 0;
	if (render_info.end_y >= WIN_SIZE_H)
		render_info.end_y = WIN_SIZE_H;
	render_info.tex_x = get_texture_scaled_x(pars , ray);
	render_info.tex_pos = (render_info.start_y - WIN_SIZE_H / 2
			+ render_info.line_height / 2) * render_info.ratio;
	return (render_info);
}
void	draw_pixel(t_data *data, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = data->bits_per_pixel / 8;
	pixel = (y * data->line_length) / color_byte + x;
	*((unsigned int *)data->addr + pixel) = color;
}

void	draw_wall(t_pars *pars, t_ray *ray, int x)
{
	t_render_info	info;
	t_data		*img_info;
	int				color;
	color = -1;

	img_info = &pars->mlx.img;
	info = get_render_info(ray, pars);
	while (info.start_y < info.end_y)
	{
		info.tex_y = (int)info.tex_pos & (TILE_SIZE - 1);
		if (ray->side == 0 && ray->ray_dir.x > 0)
			color = get_img_color(&pars->info.no, info.tex_x, info.tex_y);
		else if (ray->side == 0 && ray->ray_dir.x < 0)
			color = get_img_color(&pars->info.so, info.tex_x, info.tex_y);
		else if (ray->side == 1 && ray->ray_dir.y > 0)
			color = get_img_color(&pars->info.ea, info.tex_x, info.tex_y);
		else if (ray->side == 1 && ray->ray_dir.y < 0)
			color = get_img_color(&pars->info.we, info.tex_x, info.tex_y);
		draw_pixel(img_info, x, info.start_y, color);
		my_mlx_pixel_put(&pars->mlx.img, x, info.start_y, color);
		info.tex_pos += info.ratio;
		info.start_y++;
	}
}
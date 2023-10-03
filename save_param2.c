#include "cub3d.h"

void	save_background(t_pars *pars)
{
	pars->i = 1;
	pars->color = 0;
	pars->comma_counter = 0;
	while (++pars->i < ft_gnllen(pars->gnl))
	{
		if (ft_is_comma_num(pars->gnl[pars->i], pars) == 0)
		{
			//free();
			ft_error("Wrong parsamenters\n");
		}
	}
	pars->i = 2;
	if (pars->gnl[0] == 'C' && pars->info.ceiling.flag != 0)
	{
		//free();
		ft_error("Wrong parameters\n");
	}
	else if (pars->info.floor.flag != 0)
	{
		// free();
		ft_error("Wrong paramenters\n");
	}
	background_cycle(pars);
}

void	background_cycle(t_pars *pars)
{
	while (pars->i < ft_gnllen(pars->gnl))
	{
		pars->a = 0;
		pars->counter = 0;
		while(pars->gnl[pars->i] != ','  && pars->gnl[pars->i] != '\n')
		{	
			pars->i++;
			pars->a++;
		}
		pars->str = malloc(pars->a + 1);
		while(pars->a > 0)
		{
			pars->str[pars->counter++] = pars->gnl[pars->i - pars->a];
			pars->a--;
		}
		pars->str[pars->counter] = '\0';
	pars->i++;
	save_colors(pars);
	pars->color++;
	free(pars->str);
	}
}

void	save_colors(t_pars *pars)
{
	int n;
	n = atoi(pars->str);
	if (n > 255 || n < 0)
		//free()
		ft_error("Wrong colors");
	if (pars->gnl[0] == 'C')
	{
		if (pars->color == 0)
			pars->info.ceiling.red = n;
		if (pars->color == 1)
			pars->info.ceiling.green = n;
		if (pars->color == 2)
		{
			pars->info.ceiling.blue = n;
			pars->info.ceiling.flag++;
			pars->info.count_info++;
		}
	}
	if (pars->gnl[0] == 'F')
	{
		if (pars->color == 0)
			pars->info.floor.red = n;
		if (pars->color == 1)
			pars->info.floor.green = n;
		if (pars->color == 2)
		{
			pars->info.floor.blue = n;
			pars->info.floor.flag++;
			pars->info.count_info++;
		}
	}
}
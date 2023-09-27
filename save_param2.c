#include "cub3d.h"
// salvare red e blue in ceiling
void	save_background(t_pars *pars)
{
	int		a;
	int		i;
	char	*str;
	int		counter;
	int 	color;

	i = 1;
	color = 0;
	pars->comma_counter = 0;
	while (++i < ft_gnllen(pars->gnl))
	{
		if (ft_is_comma_num(pars->gnl[i], pars) == 0)
		{
			//free();
			ft_error("Wrong parsamenters\n");
		}
	}
	i = 2;
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
	while (i < ft_gnllen(pars->gnl))
	{
		a = 0;
		counter = 0;
		while(pars->gnl[i] != ','  && pars->gnl[i] != '\n')
		{	
			i++;
			a++;
		}
		str = malloc(a + 1);
		while(a > 0)
		{
			str[counter++] = pars->gnl[i - a];
			a--;
		}
		str[counter] = '\0';
	printf("%s\n",str);
	i++;
	save_colors(pars, color, str);
	color++;
	free(str);
	}
	pars->info.count_info++;
}

void	save_colors(t_pars *pars, int color, char *str)
{
	int n;
	n = atoi(str);
	if (n > 255 || n < 0)
		//free()
		ft_error("Wrong colors");
	if (pars->gnl[0] == 'C')
	{
		if (color == 0)
			pars->info.ceiling.red = n;
		if (color == 1)
			pars->info.ceiling.green = n;
		if (color == 2)
		{
			pars->info.ceiling.blue = n;
			pars->info.ceiling.flag++;
		}
	}
	if (pars->gnl[0] == 'F')
	{
		if (color == 0)
			pars->info.floor.red = n;
		if (color == 1)
			pars->info.floor.green = n;
		if (color == 2)
		{
			pars->info.floor.blue = n;
			pars->info.floor.flag++;
		}
	}
}
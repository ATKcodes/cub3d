#include "cub3d.h"
// salvare red e blue in ceiling
void	save_ceiling(t_pars *pars)
{
	int	a;
	int	i;
	char *str;

	a = 0;
	i = 2;
	if (pars->info.ceiling.flag != 0)
	{
		//free();
		ft_error("Wroooong parameters\n");
	}
	while(pars->gnl[i] != ','  && pars->gnl[i] != '\n')
	{
			i++;
	}

	str = malloc(i - 1);
	while(a < i - 2)
		{
			str[a] = pars->gnl[a + 2];
			a++;
		}
		str[a] = '\0';
		 printf("%s\n",str);
	pars->info.ceiling.green = atoi(str); //to change
	if (pars->info.ceiling.green > 255 || pars->info.ceiling.green < 0)
		ft_error("Wrong colors");


	printf("%d\n",pars->info.ceiling.green);

	pars->info.ceiling.flag++;
	pars->info.count_info++;
}
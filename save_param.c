#include "cub3d.h"

void	save_north(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.NO.flag != 0)
	{
		//free();
		ft_error("Wrong parameters\n");
	}
	pars->info.NO.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.NO.addr[i] = pars->gnl[i + 3];
	pars->info.NO.addr[i] = '\0';
	printf("%s\n", pars->info.NO.addr);
	fd = open(pars->info.NO.addr, O_RDONLY);
	close(fd);
	if(fd == -1)
	{
		// free();
		ft_error("Wrong address\n");
	}
	pars->info.NO.flag++;
	pars->info.count_info++;
}

void	save_south(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.SO.flag != 0)
	{
		//free();
		ft_error("Wrong parameters\n");
	}
	pars->info.SO.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.SO.addr[i] = pars->gnl[i + 3];
	pars->info.SO.addr[i] = '\0';
	printf("%s\n", pars->info.SO.addr);
	fd = open(pars->info.SO.addr, O_RDONLY);
	close(fd);
	if(fd == -1)
	{
		// free();
		ft_error("Wrong address\n");
	}
	pars->info.SO.flag++;
	pars->info.count_info++;
}

void	save_east(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.EA.flag != 0)
	{
		//free();
		ft_error("Wrong parameters\n");
	}
	pars->info.EA.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.EA.addr[i] = pars->gnl[i + 3];
	pars->info.EA.addr[i] = '\0';
	printf("%s\n", pars->info.EA.addr);
	fd = open(pars->info.EA.addr, O_RDONLY);
	close(fd);
	if(fd == -1)
	{
		// free();
		ft_error("Wrong address\n");
	}
	pars->info.EA.flag++;
	pars->info.count_info++;
}

void	save_west(t_pars *pars)
{
	int	fd;
	int	i;

	i = -1;
	if (pars->info.WE.flag != 0)
	{
		//free();
		ft_error("Wrong parameters\n");
	}
	pars->info.WE.addr = malloc (ft_gnllen(pars->gnl) - 2);
	while (++i + 3 < ft_gnllen(pars->gnl))
		pars->info.WE.addr[i] = pars->gnl[i + 3];
	pars->info.WE.addr[i] = '\0';
	printf("%s\n", pars->info.WE.addr);
	fd = open(pars->info.WE.addr, O_RDONLY);
	close(fd);
	if(fd == -1)
	{
		// free();
		ft_error("Wrong address\n");
	}
	pars->info.WE.flag++;
	pars->info.count_info++;
}
void init_flags(t_pars *pars)
{
	pars->info.NO.flag = 0;
	pars->info.EA.flag = 0;
	pars->info.WE.flag = 0;
	pars->info.SO.flag = 0;
	pars->info.ceiling.flag = 0;
	pars->info.floor.flag = 0;
	
}
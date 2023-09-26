#include "cub3d.h"

void	get_info(t_pars *pars)
{
	pars->info.count_info = 0;
	while(pars->info.count_info < 6)
	{
		pars->gnl = get_next_line(pars->fd);
		if (ft_gnllen(pars->gnl) > 0 && ft_gnllen(pars->gnl) < 6)
			ft_error("Invalid parameters");
		if (ft_gnllen(pars->gnl) >= 6)
			{
				if (pars->gnl[0] == 'N' && pars->gnl[1] == 'O' && pars->gnl[2] == ' ')
					save_north(pars);
				// else if(pars->gnl[0] == 'S' && pars->gnl[1] == 'O' && pars->gnl[2] == ' ')
				// 	save_south(pars);
				// else if(pars->gnl[0] == 'E' && pars->gnl[1] == 'A' && pars->gnl[2] == ' ')
				// 	save_east(pars);
				// else if(pars->gnl[0] == 'W' && pars->gnl[1] == 'E' && pars->gnl[2] == ' ')
				// 	save_west(pars);
				else if(pars->gnl[0] == 'C' && pars->gnl[1] == ' ')
					save_ceiling(pars);
				// else if(pars->gnl[c] == 'F' && pars->gnl[c + 1] == ' ')
				// 	save_floor(pars);
				// else
				// 	ft_error("Invalid parameters");				
			}
		pars->info.count_info++;
		free(pars->gnl);
	}
}
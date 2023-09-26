#include "cub3d.h"

void	count_rows(t_pars *pars)
{
	pars->rows = 0;
	pars->gnl = get_next_line(pars->fd);
	if (pars->gnl == NULL || pars->gnl == 0)
		ft_error("Invalid reading\n");
	while(pars->gnl)
	{
		free (pars->gnl);
		pars->gnl = get_next_line(pars->fd);
		pars->rows++;
	}
	close(pars->fd);
	pars->matrix = malloc (sizeof(char *) * (pars->rows));
}

void	check_characters(t_pars *pars)
{
	int	i;
	int	d;
	int	counter;

	i = -1;
	counter = 0;
	while (++i < pars->rows)
	{
		d = -1;
		while (++d < ft_strlen(pars->matrix[i]))
		{
			if (pars->matrix[i][d] != '0' && pars->matrix[i][d] != '1' && pars->matrix[i][d] != ' ')
			{
				if ((pars->matrix[i][d] == 'N' || pars->matrix[i][d] == 'S' || pars->matrix[i][d] == 'E' || pars->matrix[i][d] == 'W') && counter == 0)
					counter++;
				else
				{
					// free_matrix(pars);
					ft_error("Invalid characters\n");
				}
			}
		}
	}
}

void	check_borders(t_pars *pars)
{
	pars->y = 0;

	while(pars->y < pars->rows)
	{
		pars->x = 0;
		while((pars->y == 0 || pars->y == pars->rows - 1) && pars->x < ft_strlen(pars->matrix[pars->y]))
		{
			if(pars->matrix[pars->y][pars->x] != '1' && pars->matrix[pars->y][pars->x] != ' ')
				{
					//free_matrix(pars);
					ft_error("Invalid Mapssss\n"); 
				}
			pars->x++;
		} 
		check_rows(pars);
		pars->y++;
	}
}

void	check_rows(t_pars *pars)
{
	int flag;
	flag = 0;
	printf ("%d : \n", pars->y);
	while(pars->y != 0 && pars->y != pars->rows - 1 && pars->x < ft_strlen(pars->matrix[pars->y]))
	{
		while(pars->matrix[pars->y][pars->x] == ' ')
		{
			if(pars->matrix[pars-> y][pars->x +1] == '1')
				{
					pars->x++;
					break;
				}	
			
			pars->x++;
		}
		if(pars->matrix[pars-> y][pars->x] != '1' && flag == 0)
		{
			printf("%d\n", pars->matrix[pars-> y][pars->x]);
				//free_matrix(pars);
			ft_error("Invalid Map\n"); 
		}
		else
			flag++;
		pars->x++;
	}
}
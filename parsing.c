#include "cub3d.h"

void	count_rows(t_pars *pars)
{
	pars->rows = 0;
	pars->gnl = NULL;
	pars->gnl = get_next_line(pars->fd);
	if (pars->gnl == NULL || pars->gnl == 0)
		ft_error("Invalid reading\n");
	while(pars->gnl)
	{
		free (pars->gnl);
		pars->gnl = get_next_line(pars->fd);
		pars->rows++;
	}
	free (pars->gnl);
	close(pars->fd);
	pars->matrix = calloc (sizeof(char *) * (pars->rows), 1); //tADD FTCALLOC
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
				{
					pars->player.y = (float)i + 0.5;
					pars->player.x = (float)d + 0.5;
					pars->player.view = pars->matrix[i][d];
					pars->matrix[i][d] = '0';
					counter++;
				}
				else
				{
					ft_error("Invalid characters\n");
					free_matrix(pars);
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
					ft_error("Invalid Map\n"); 
					free_matrix(pars);
				}
			pars->x++;
		} 
		check_rows(pars);
		pars->y++;
	}
}

void	check_rows(t_pars *pars)
{
	while(pars->y != 0 && pars->y != pars->rows - 1
		&& pars->x < ft_strlen(pars->matrix[pars->y]))
	{
		if(pars->x == 0 && pars->matrix[pars->y][pars->x] == '0')
		{
			free_matrix(pars);
			ft_error("Invalid map\n");
		}
		else if (pars->matrix[pars->y][pars->x] == '0'
			&& (pars->matrix[pars->y - 1][pars->x] != '1'
				&& pars->matrix[pars->y - 1][pars->x] != '0'))
		{
			free_matrix(pars);
			ft_error("Invalid map\n");
		}
		check_rows2(pars);
		pars->x++;
	}
}

void	check_rows2(t_pars *pars)
{
	if (pars->matrix[pars->y][pars->x] == '0'
		&& (pars->matrix[pars->y + 1][pars->x] != '1'
			&& pars->matrix[pars->y + 1][pars->x] != '0'))
	{
		ft_error("Invalid map\n");
		free_matrix(pars);
	}
	else if (pars->matrix[pars->y][pars->x] == '0'
		&& (pars->matrix[pars->y][pars->x + 1] != '1'
			&& pars->matrix[pars->y][pars->x + 1] != '0'))
	{
		ft_error("Invalid map\n");
		free_matrix(pars);
	}
	else if (pars->matrix[pars->y][pars->x] == '0'
		&& (pars->matrix[pars->y][pars->x - 1] != '1'
			&& pars->matrix[pars->y][pars->x - 1] != '0'))
	{
		ft_error("Invalid map\n");
		free_matrix(pars);
	}
}
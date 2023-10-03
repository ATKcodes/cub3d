/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:48 by amaso             #+#    #+#             */
/*   Updated: 2023/09/20 19:57:51 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(t_pars *pars)
{
	int	i;
	int	d;

	i = -1;
	while (++i < pars->rows )
	{
		d = -1;
		pars->gnl = get_next_line(pars->fd);
		pars->matrix[i] = malloc (ft_gnllen(pars->gnl) + 1);
		while(++d < ft_gnllen(pars->gnl))
			pars->matrix[i][d] = pars->gnl[d]; 
		pars->matrix[i][d] = '\0';
	}
	check_characters(pars);
	check_borders(pars);
	for (int d = 0; d < pars->rows; d++)
		printf("%s\n", pars->matrix[d]);
}

int	main(int argc, char *argv[])
{
	t_pars	pars;
	if (argc != 2)
		ft_error("Invalid arguments\n");
	if (ft_strlen(argv[1]) < 5 || argv[1][ft_strlen(argv[1]) - 4] != '.'
			|| argv[1][ft_strlen(argv[1]) - 3] != 'c'
				|| argv[1][strlen(argv[1]) - 2] != 'u'
					|| argv[1][strlen(argv[1]) - 1] != 'b')
		ft_error("Invalid file\n");
	pars.fd = open(argv[1], O_RDONLY);
	if (pars.fd == -1)
		ft_error("Invalid file\n");
	count_rows(&pars);
	pars.fd = open(argv[1], O_RDONLY);
	init_flags(&pars);
	get_info(&pars);
	parsing(&pars);
	new_window(&pars);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaso <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 19:57:41 by amaso             #+#    #+#             */
/*   Updated: 2023/09/20 19:57:44 by amaso            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gnl/get_next_line.h"

typedef struct s_pars{

	int		fd;
	int		x;
    int		y;
	int		curr_x;
	int		curr_y;
	char	**matrix;
	char	*gnl;
	int		rows;
	}	t_pars;

void	ft_error(char *str);

int		ft_gnllen(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

void	count_rows(t_pars *pars);

void	parsing(t_pars *pars);
void	check_characters(t_pars *pars);
void	check_borders(t_pars *pars);
void	check_rows(t_pars *pars);
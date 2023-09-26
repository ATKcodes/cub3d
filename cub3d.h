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

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		flag;
}				t_data;

typedef struct s_color {
	int red;
	int green;
	int	blue;
	int	flag;
}	t_color;

typedef struct s_info {
	t_color ceiling;
	t_color	floor;
	t_data	SO;		
	t_data	NO;
	t_data	EA;
	t_data	WE;
	int		start_map;
	int		count_info;
}	t_info;

	typedef struct s_pars{
	int		fd;
	int		x;
    int		y;
	int		curr_x;
	int		curr_y;
	char	**matrix;
	char	*gnl;
	int		rows;
	t_info	info;
	}	t_pars;

void	ft_error(char *str);
void	init_flags(t_pars *pars);

int		ft_gnllen(char *str);
void	ft_putstr(char *str);
int		ft_strlen(char *str);

void	count_rows(t_pars *pars);
void	get_info(t_pars *pars);

void	parsing(t_pars *pars);
void	check_characters(t_pars *pars);
void	check_borders(t_pars *pars);
void	check_rows(t_pars *pars);

void	save_north(t_pars *pars);
void	save_ceiling(t_pars *pars);
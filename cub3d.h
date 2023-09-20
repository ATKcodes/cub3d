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

typedef struct t_pars{

	int		fd;
	int		x;
    int		y;
	int		curr_x;
	int		curr_y;
	char	**matrix;

	}	s_pars;

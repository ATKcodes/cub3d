#include "cub3d.h"

int		ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int		ft_gnllen(char *str)
{
	int	i = 0;

	if(!str)
		return(0);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i = -1;
	int	a;

	while (str[++i])
		a += write(1, &str[i], 1);
}

int	ft_is_comma_num(int c, t_pars *pars)
{
	if ((c >= 48) && (c <= 57))
		return (1);
	else if (c == 44 && pars->comma_counter < 2)
	{
		pars->comma_counter++;
		return (1);
	}
	else
		return (0);
}
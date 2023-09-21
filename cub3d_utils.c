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

	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	int	i = -1;

	while (str[++i])
		write(1, &str[i], 1);
}
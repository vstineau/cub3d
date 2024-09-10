#include "../../includes/cub3d.h"

void	ft_err(char *arg, char *err)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(err, 2);
	if (arg)
	{
		ft_putstr_fd(arg, 2);
		ft_putstr_fd("\n", 2);
	}
}

bool	only_digit_string(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			i++;
		else
			return (true);
	}
	return (false);
}

bool	overflow(char *s)
{
	int			i;
	int			sign;
	int			nbr;

	i = 0;
	sign = 1;
	nbr = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == ' ')
		i++;
	if (only_digit_string(s + i))
		return (true);
	while (s[i] >= '0' && s[i] <= '9')
	{
		nbr = (nbr * 10 + s[i++] - '0');
		if (nbr * sign > 255 || nbr * sign < 0)
			return (true);
	}
	return (false);
}

void	print_color_error(char *color_one, char *color_two, char c)
{
	if (color_one)
		ft_putstr_fd(color_one, 2);
	if (color_two)
		ft_putstr_fd(color_two, 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd(RESET, 2);
}

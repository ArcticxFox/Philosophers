#include "../header/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

int	ft_isnb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	parsing(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac != 5)
	{
		printf("invalid parameters\n");
		return (0);
	}
	while (i < ac)
	{
		if (!ft_isnb(av[i]))
		{
			printf("invalid parameters\n");
			return (0);
		}
		i++;
	}
	return (1);
}

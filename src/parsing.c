/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejones <ejones.42angouleme@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 14:38:26 by ejones            #+#    #+#             */
/*   Updated: 2026/03/19 14:38:34 by ejones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/philo.h"

static void	print_format(void)
{
	printf("./philo <nb_of_philos> <time_to_die> ");
	printf("<time_to_eat> <time_to_sleep>\n");
	printf("./philo <nb_of_philos> <time in ms> ");
	printf("<time in ms> <time in ms>\n");
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
		print_format();
		return (0);
	}
	while (i < ac)
	{
		if (!ft_isnb(av[i]))
		{
			print_format();
			return (0);
		}
		i++;
	}
	return (1);
}

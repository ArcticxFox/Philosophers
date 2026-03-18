#include "../header/philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	struct timeval	st_death_evt;
	short int	left;
	short int	right;

	philo = (t_philo *)arg;
	gettimeofday(&st_death_evt, NULL);
	left = philo->id;
	right = (philo->id + 1) % philo->nb_philos;
	while (philo->state != DEAD 
	&& philo->time_to_die - elapsed_time(st_death_evt) >= 0)
	{
		pthread_mutex_lock(&philo->forks[left]);
		pthread_mutex_lock(&philo->forks[right]);
		philo->state = EATING;
		if (!ft_event(&st_death_evt, philo))
			break;
		philo->state = SLEEPING;		
		pthread_mutex_lock(&philo->forks[left]);
		pthread_mutex_unlock(&philo->forks[right]);
		if (!ft_event(&st_death_evt, philo))
			break;
		philo->state = THINKING;
	}
	return (NULL);
}

t_philo	*init_philos(char **av)
{
	int		i;
	short int	nb_philos;
	t_philo		*philos;
	pthread_mutex_t	*forks;
	
	i = 0;
	nb_philos = atoi(av[1]);	
	philos = malloc(sizeof(t_philo) * nb_philos);
	forks = malloc(sizeof(pthread_mutex_t) * nb_philos);
	while (i < nb_philos)
	{
		philos[i].id = i;
		philos[i].nb_philos = nb_philos;
		pthread_mutex_init(&forks[i], NULL);
		philos[i].forks = forks;
		philos[i].time_to_die = atoi(av[2]);
		philos[i].time_to_eat = atoi(av[3]);
		philos[i].time_to_sleep = atoi(av[4]);
		philos[i].state = THINKING;
		i++;
	}
	return (philos);
}

int	main(int ac, char **av)
{
	t_philo		*philos;
	
	philos = NULL;
	if (!parsing(ac, av))
		return (0);	
	philos = init_philos(av);
	manage_thread(philos, philos[0].forks, philos[0].nb_philos);
	free(philos[0].forks);
	free(philos);
	return (0);
}

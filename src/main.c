#include "../header/philo.h"

void	*philo_routine(void *arg)
{
	t_philo		*philo;
	struct timeval	st_death_evt;
	struct timeval	start;
	short int	left;
	short int	right;

	philo = (t_philo *)arg;
	gettimeofday(&st_death_evt, NULL);
	gettimeofday(&start, NULL);
	left = philo->id;
	right = (philo->id + 1) % philo->nb_philos;
	while (philo->time_to_die - elapsed_time(st_death_evt) >= 0)
	{
		ft_lock(philo, left, right);
		printf("%ld %d has taken a fork\n", elapsed_time(start), philo->id);
		philo->state = EATING;
		gettimeofday(&st_death_evt, NULL);
		printf("%ld %d is eating\n", elapsed_time(start), philo->id);
		usleep(philo->time_to_eat * 1000);

		ft_unlock(philo, left, right);

		philo->state = SLEEPING;
		printf("%ld %d is sleeping\n", elapsed_time(start), philo->id);
		usleep(philo->time_to_sleep * 1000);

		philo->state = THINKING;
		printf("%ld %d is thinking\n", elapsed_time(start), philo->id);

	}
	printf("philo %d is DEAD\n", philo->id);
	return (NULL);
}

t_philo	*init_philos(char **av)
{
	short int	i;
	short int	nb_philos;
	t_philo		*philos;
	pthread_mutex_t	*forks;

	i = 0;
	nb_philos = ft_atoi(av[1]);
	philos = malloc(sizeof(t_philo) * nb_philos);
	forks = malloc(sizeof(pthread_mutex_t) * nb_philos);
	while (i < nb_philos)
	{
		philos[i].id = i;
		philos[i].nb_philos = nb_philos;
		philos[i].end_simulation = philos[0].end_simulation;
		pthread_mutex_init(&forks[i], NULL);
		philos[i].forks = forks;
		philos[i].time_to_die = ft_atoi(av[2]);
		philos[i].time_to_eat = ft_atoi(av[3]);
		philos[i].time_to_sleep = ft_atoi(av[4]);
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
	free(philos[0].end_simulation);
	free(philos);
	return (0);
}

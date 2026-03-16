#include "../header/philo.c"


short int	elapsed_time(struct timeval *death, t_philo *philo, long int max_time)
{
	long int	elapsed;
	struct timeval	start;
	struct timeval	end;
	
	gettimeofday(&start, NULL);
	elapsed = 0;
	while (max_time - elapsed >= 0)
	{
		gettimeofday(&end, NULL);
		elapsed = (end.tv_sec - start.tv_sec) * 1000 
			+ (end.tv_usec - start.tv_usec) * 1000;
		if (elapsed >= philo->time_to_die && philo->state != EATING)
		{
			philo->state = DEAD;
			printf("a philo has died");
			return (EXIT_FAILURE);
		}
	}
	printf("Elapsed time: %lu seconds\n", elapsed);
	if (philo->state == EATING)
		gettimeofday(death, NULL);
	if (philo->state != THINKING)
		philo->state += 1;
	return (EXIT_SUCCESS);
}


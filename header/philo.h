#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

//SECOND IDEA
typedef enum	e_state
{
    DEAD = 1,
    EATING,
    SLEEPING,
    THINKING
}	t_state;

typedef struct	s_philo
{
	short int	id;
	short int	nb_philo;
	pthread_t	thread;
	pthread_mutex_t	*forks;
	long int	time_to_die;
	long int	time_to_eat;
	long int	time_to_sleep;
	t_state		state;
}	t_philo;



#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 10:33:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_fork(t_fork *fork)
{
	fork->status = IS_FREE;
}

int	take_fork(t_fork *fork)
{
	if (fork)
	{
		pthread_mutex_lock(&(fork->m_fork));
		if (fork->status == IS_FREE)
		{
			fork->status = IS_TAKEN;
			pthread_mutex_unlock(&(fork->m_fork));
			return (SUCCESS);
		}	
		pthread_mutex_unlock(&(fork->m_fork));
	}
	return (FAILLURE);
}

void	eating_routine(t_philo *philo)
{
	if (take_fork(philo->fork_right) == SUCCESS)
	{
		if (take_fork(philo->fork_left) == SUCCESS)
		{
			print_status(philo, TAKEN_FORK);
			print_status(philo, TAKEN_FORK);
			print_status(philo, IS_EATING);
			gettimeofday(&(philo)->last_eat, NULL);
			philo->status = IS_EATING;
			philo->nb_eat += 1;
			ms_sleep(philo->rules->time_to_eat);
			drop_fork(philo->fork_right);
			drop_fork(philo->fork_left);
		}
		else if (philo->fork_left == NULL)
			print_status(philo, TAKEN_FORK);
		else
			drop_fork(philo->fork_right);
	}
}

void	*routine(void *philosopher)
{
	t_philo		*philo;
	int			max_eat;

	philo = (t_philo *)philosopher;
	max_eat = philo->rules->nb_meal;

	//	printf("philo n°%d\n", philo->id);
		//while (philo->nb_eat < philo->rules->nb_meal)
	while (philo->status == IS_DEAD)
		ms_sleep(1);

	gettimeofday(&(philo)->last_eat, NULL);
	while(philo->status != IS_DEAD
		|| (max_eat != -1 && philo->nb_eat < max_eat))
	{
		if (philo->status == IS_THINKING)
			eating_routine(philo);
		else if (philo->status == IS_EATING)
		{
			philo->status = IS_SLEEPING;
			print_status(philo, IS_SLEEPING);
			ms_sleep(philo->rules->time_to_sleep);
		}
		else if (philo->status == IS_SLEEPING)
		{
			philo->status = IS_THINKING;
			print_status(philo, IS_THINKING);
		}
	}
	return (NULL);
}

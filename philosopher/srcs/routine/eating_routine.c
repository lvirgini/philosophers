/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:25:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/25 14:25:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	drop_fork(t_fork *fork)
{
	pthread_mutex_lock(&(fork->m_fork));
	fork->status = IS_FREE;
	pthread_mutex_unlock(&(fork->m_fork));
}

static int	take_fork(t_fork *fork)
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
	ft_usleep(200);
	return (FAILLURE);
}

static void	give_spaghetti_to_the_philosopher(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	philo->nb_eat += 1;
	if (philo->nb_eat == philo->rules->nb_meal)
		philo->status = FINISHED_EATING;
	else
		philo->status = IS_EATING;
	gettimeofday(&philo->last_eat, NULL);
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_EATING, philo->rules);
	ms_sleep(philo->rules->time_to_eat, philo->rules);
}

void	eating_routine(t_philo *philo)
{
	if (take_fork(philo->fork_right) == SUCCESS)
	{
		print_status(philo, TAKEN_FORK, philo->rules);
		if (philo->fork_left == NULL)
			return ;
		while (take_fork(philo->fork_left) != SUCCESS)
			if (can_write(philo->rules) == FAILLURE)
				return ;
		print_status(philo, TAKEN_FORK, philo->rules);
		give_spaghetti_to_the_philosopher(philo);
		drop_fork(philo->fork_right);
		drop_fork(philo->fork_left);
	}
}

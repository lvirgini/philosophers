/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:25:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:29:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	drop_fork(t_fork *fork)
{
	fork->status = IS_FREE;
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
			gettimeofday(&(philo)->last_eat, NULL);
			philo->status = IS_EATING;
			philo->nb_eat += 1;
			print_status(philo, IS_EATING);
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

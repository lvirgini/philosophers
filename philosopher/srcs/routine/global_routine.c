/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 13:01:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleeping_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	philo->status = IS_SLEEPING;
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_SLEEPING, philo->rules);
	ms_sleep(philo->rules->time_to_sleep);
}

static void	thinking_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	philo->status = IS_THINKING;
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_THINKING, philo->rules);
}

int		can_write(t_rules *rules)
{
	pthread_mutex_lock(&rules->m_print);
	if (rules->able_to_write == false)
	{
		pthread_mutex_unlock(&rules->m_print);
		return (false);
	}
	pthread_mutex_unlock(&rules->m_print);
	return (true);
}

void	*routine(void *philosopher)
{
	t_philo		*philo;
	int			max_eat;

	philo = (t_philo *)philosopher;
	max_eat = philo->rules->nb_meal;
	ms_sleep(1);
//	pthread_mutex_lock(&philo->m_status);
	gettimeofday(&(philo)->last_eat, NULL);
//	pthread_mutex_unlock(&philo->m_status);
	while (max_eat == -1 || philo->nb_eat < max_eat)
	{
		if (philo->status == FINISHED_EATING || philo->status == IS_DEAD
			|| can_write(philo->rules) == false)
			return (NULL);
		else if (philo->status == IS_THINKING)
			eating_routine(philo);
		else if (philo->status == IS_EATING)
			sleeping_routine(philo);
		else if (philo->status == IS_SLEEPING)
			thinking_routine(philo);
	//	pthread_mutex_unlock(&philo->m_status);
	}
	return (NULL);
}
/*
void	*routine(void *philosopher)
{
	t_philo		*philo;
	int			max_eat;

	philo = (t_philo *)philosopher;
	max_eat = philo->rules->nb_meal;
	ms_sleep(10);
	pthread_mutex_lock(&philo->m_status);
	gettimeofday(&(philo)->last_eat, NULL);
	pthread_mutex_unlock(&philo->m_status);
	while (1)
	{
		//pthread_mutex_lock(&philo->m_status);
		if (philo->status == IS_DEAD
			&& (max_eat != -1 || philo->nb_eat >= max_eat))
		{
			//pthread_mutex_unlock(&philo->m_status);
			return (NULL);
		}	
		if (philo->status == IS_THINKING)
			eating_routine(philo);
		else if (philo->status == IS_EATING)
			sleeping_routine(philo);
		else if (philo->status == IS_SLEEPING)
			thinking_routine(philo);
	//	pthread_mutex_unlock(&philo->m_status);
		usleep(1);
	}
			
//	}
	//printf("philo %d status = %d\n", philo->id, philo->status);

	return (NULL);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/27 11:16:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** Sleeping
*/

static void	sleeping_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	philo->status = IS_SLEEPING;
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_SLEEPING, philo->rules);
	ms_sleep(philo->rules->time_to_sleep, philo->rules);
}

/*
** Thinking
*/

static void	thinking_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	philo->status = IS_THINKING;
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_THINKING, philo->rules);
	ft_usleep(10);
}

/*
** if rules->able_to_print == false
** => one philo is already dead
** stop all philo's routine
*/

int	can_write(t_rules *rules)
{
	if (!rules)
		return (true);
	pthread_mutex_lock(&rules->m_print);
	if (rules->able_to_write == false)
	{
		pthread_mutex_unlock(&rules->m_print);
		return (false);
	}
	pthread_mutex_unlock(&rules->m_print);
	return (true);
}

int	it_is_start(t_philo *philo)
{
	pthread_mutex_lock(&philo->m_status);
	if (philo->status == IS_THINKING)
	{
		pthread_mutex_unlock(&philo->m_status);
		return (true);
	}
	pthread_mutex_unlock(&philo->m_status);
	return (false);
}

/*
**  while philo is not dead || philo finished eating 
**	|| main stop able to write some status == one other philo is dead
**
** 	EAT then SLEEP then THINK
*/

void	*routine(void *philosopher)
{
	t_philo		*philo;

	philo = (t_philo *)philosopher;
	while (philo->status != FINISHED_EATING && philo->status != IS_DEAD
		&& can_write(philo->rules) == true)
	{
		if (philo->status == IS_THINKING)
		{
			if (philo->id % 2 == 0)
				eating_routine_even(philo);
			else
				eating_routine_odd(philo);
		}
		else if (philo->status == IS_EATING)
			sleeping_routine(philo);
		else if (philo->status == IS_SLEEPING)
			thinking_routine(philo);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/01 15:16:03 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** Sleeping
*/

static void	sleeping_routine(t_philo *philo)
{
	change_status(philo, IS_SLEEPING);
	print_status(philo, IS_SLEEPING, philo->rules);
	ms_sleep(philo->rules->time_to_sleep, philo->rules);
}

/*
** Thinking
*/

static void	thinking_routine(t_philo *philo)
{
	change_status(philo, IS_THINKING);
	pthread_mutex_unlock(&philo->m_status);
	print_status(philo, IS_THINKING, philo->rules);
	usleep(10);
}

/*
**  while philo is not dead || philo finished eating 
**
** 	EAT then SLEEP then THINK
*/

void	*routine(void *philosopher)
{
	t_philo		*philo;
	int			even_odd;

	philo = (t_philo *)philosopher;
	even_odd = philo->id % 2;
	while (can_write(philo->rules))
	{
		if (philo->status == IS_THINKING)
		{
			if (even_odd == 0)
				eating_routine_even(philo);
			else
				eating_routine_odd(philo);
		}
		else if (philo->status == IS_EATING)
			sleeping_routine(philo);
		else if (philo->status == IS_SLEEPING)
			thinking_routine(philo);
		else
			return (NULL);
	}
	return (NULL);
}

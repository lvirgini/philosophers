/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/02 09:35:55 by lvirgini         ###   ########.fr       */
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
	print_status(philo, IS_THINKING, philo->rules);
}

/*
** "possible data race with valgrind
** because of read here and write in main thread..."
*/

static int	get_status(t_philo *philo)
{
	int		status;

	pthread_mutex_lock(&philo->m_status);
	status = philo->status;
	pthread_mutex_unlock(&philo->m_status);
	return (status);
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
	int			status;

	philo = (t_philo *)philosopher;
	even_odd = philo->id % 2;
	while (can_write(philo->rules))
	{
		status = get_status(philo);
		if (status == IS_THINKING)
		{
			if (even_odd == 0)
				eating_routine_even(philo);
			else
				eating_routine_odd(philo);
		}
		else if (status == IS_EATING)
			sleeping_routine(philo);
		else if (status == IS_SLEEPING)
			thinking_routine(philo);
		else
			return (NULL);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:29:31 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	sleeping_routine(t_philo *philo)
{
	philo->status = IS_SLEEPING;
	print_status(philo, IS_SLEEPING);
	ms_sleep(philo->rules->time_to_sleep);
}

static void	thinking_routine(t_philo *philo)
{
	philo->status = IS_THINKING;
	print_status(philo, IS_THINKING);
}

void	*routine(void *philosopher)
{
	t_philo		*philo;
	int			max_eat;

	philo = (t_philo *)philosopher;
	max_eat = philo->rules->nb_meal;
	while (philo->status == IS_DEAD)
		ms_sleep(1);
	gettimeofday(&(philo)->last_eat, NULL);
	while (philo->status != IS_DEAD
		&& (max_eat != -1 && philo->nb_eat < max_eat))
	{
		if (philo->status == IS_THINKING)
			eating_routine(philo);
		else if (philo->status == IS_EATING)
			sleeping_routine(philo);
		else if (philo->status == IS_SLEEPING)
			thinking_routine(philo);
	}
	return (NULL);
}

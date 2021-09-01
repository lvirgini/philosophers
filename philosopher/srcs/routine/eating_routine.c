/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 11:25:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/31 15:32:20 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	drop_fork(t_fork *fork)
{
	pthread_mutex_unlock(&fork->m_fork);
}

static void	take_fork(t_philo *philo, t_fork *fork)
{
	pthread_mutex_lock(&fork->m_fork);
	print_status(philo, TAKEN_FORK, philo->rules);
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

/*
**	eating routine: for philosophers even.
*/

void	eating_routine_even(t_philo *philo)
{
	take_fork(philo, philo->fork_left);
	take_fork(philo, philo->fork_right);
	give_spaghetti_to_the_philosopher(philo);
	drop_fork(philo->fork_right);
	drop_fork(philo->fork_left);
}

/*
**	eating routine: for philosophers odd.
**	if there is no fork on the left, it means that there is only one philosopher
**	and cannot eat.
*/

void	eating_routine_odd(t_philo *philo)
{
	take_fork(philo, philo->fork_right);
	if (philo->fork_left == NULL)
	{
		drop_fork(philo->fork_right);
		pthread_mutex_lock(&philo->m_status);
		philo->status = IS_DEAD;
		pthread_mutex_unlock(&philo->m_status);
		return ;
	}
	take_fork(philo, philo->fork_left);
	give_spaghetti_to_the_philosopher(philo);
	drop_fork(philo->fork_left);
	drop_fork(philo->fork_right);
}

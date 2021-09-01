/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:58:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/01 16:57:40 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** the simulation is started in even / odd so that the philosophers cannot all 
**	be blocked with a fork each.
*/

static void	init_the_begin_time(t_rules *rules, t_philo *philo, int nb_philo)
{
	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&rules->begin, NULL);
	while (nb_philo--)
	{
		philo[nb_philo].last_eat.tv_sec = rules->begin.tv_sec;
		philo[nb_philo].last_eat.tv_usec = rules->begin.tv_usec;
	}	
	pthread_mutex_unlock(&rules->m_print);
}

int	make_it_start(int nb_philo, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (!(i % 2))
		{
			if (create_philo_thread(philo + i) == FAILLURE)
				return (FAILLURE);
		}
		i++;
	}
	ms_sleep(1, NULL);
	i = 0;
	while (i < nb_philo)
	{
		if (i % 2)
		{
			if (create_philo_thread(philo + i) == FAILLURE)
				return (FAILLURE);
		}
		i++;
	}
	return (SUCCESS);
}

/*
** 	checks if all the philosophers have eaten the necessary number of meals.
**	check if no philosopher is dead.
**		if last_eat > time_to_die : he is dead.
*/

static int	is_dead_or_finished_eating(t_philo *philo, int nb_philo,
	int max_eat, t_ms time_to_die)
{
	int				nb_finished_eating;
	int				i;
	struct timeval	now;
	t_ms			last_eat;

	i = -1;
	nb_finished_eating = 0;
	while (++i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].m_status);
		if (max_eat != -1 && philo[i].status == FINISHED_EATING)
			nb_finished_eating++;
		gettimeofday(&now, NULL);
		last_eat = get_diff_time_ms(philo[i].last_eat, now);
		if (last_eat > 0 && last_eat > time_to_die)
		{
			print_status(&philo[i], IS_DEAD, philo->rules);
			pthread_mutex_unlock(&philo[i].m_status);
			return (true);
		}	
		pthread_mutex_unlock(&philo[i].m_status);
	}
	if (nb_finished_eating == nb_philo)
		return (true);
	return (false);
}

/*
** make all philo status to "FINISHED EATING" for stop all thread
**	and join them after.
*/

void	make_it_stop(t_philo *philo, int nb_philo)
{
	while (nb_philo--)
	{
		pthread_mutex_lock(&philo[nb_philo].m_status);
		philo[nb_philo].status = FINISHED_EATING;
		pthread_mutex_unlock(&philo[nb_philo].m_status);
	}
}

/*
** init begin time, init philo thread, check all 1ms if one is dead
** or if all finished eating
*/

int	start_simulation(t_dinner_table *table, t_rules *rules, t_philo *philo,
	int nb_philo)
{
	init_the_begin_time(rules, philo, nb_philo);
	if (make_it_start(nb_philo, philo) == FAILLURE)
		return (philo_error(ERR_THREAD_INIT, table));
	while (is_dead_or_finished_eating(philo, nb_philo, rules->nb_meal,
			rules->time_to_die) == false)
		ms_sleep(1, NULL);
	make_it_stop(philo, nb_philo);
	return (SUCCESS);
}

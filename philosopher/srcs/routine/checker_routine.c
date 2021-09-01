/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:58:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/31 16:37:56 by lvirgini         ###   ########.fr       */
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
** checks if all the philosophers have eaten the necessary number of meals.
*/

static int	check_max_eat(t_philo *philo, int nb_philo, int max_eat)
{
	int		i;

	if (max_eat == -1)
		return (FAILLURE);
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].m_status);
		if (philo[i].status != FINISHED_EATING)
		{
			pthread_mutex_unlock(&philo[i].m_status);
			return (FAILLURE);
		}
		pthread_mutex_unlock(&philo[i].m_status);
		i++;
	}
	return (SUCCESS);
}

/*
**	check if no philosopher is dead.
**	if last_eat > time_to_die : he is dead.
*/

static int	is_dead_philo(t_philo *philo, int nb_philo, t_ms time_to_die)
{
	struct timeval	now;
	t_ms			last_eat;

	while (nb_philo)
	{
		nb_philo--;
		pthread_mutex_lock(&philo[nb_philo].m_status);
		gettimeofday(&now, NULL);
		last_eat = get_diff_time_ms(philo[nb_philo].last_eat, now);
		if (last_eat > 0 && last_eat > time_to_die)
		{
			print_status(&philo[nb_philo], IS_DEAD, philo->rules);
			pthread_mutex_unlock(&philo[nb_philo].m_status);
			return (true);
		}	
		pthread_mutex_unlock(&philo[nb_philo].m_status);
	}
	return (false);
}

int	start_simulation(t_dinner_table *table, t_rules *rules, t_philo *philo,
	int nb_philo)
{
	init_the_begin_time(rules, philo, nb_philo);
	if (make_it_start(nb_philo, philo) == FAILLURE)
		return (philo_error(ERR_THREAD_INIT, table));
	ms_sleep(1, NULL);
	while (check_max_eat(philo, nb_philo, rules->nb_meal) == FAILLURE)
	{
		if (is_dead_philo(philo, nb_philo, rules->time_to_die) == true)
			return (SUCCESS);
		ms_sleep(1, NULL);
	}
	return (SUCCESS);
}

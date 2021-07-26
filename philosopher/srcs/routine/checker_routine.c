/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:58:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 12:55:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	make_it_start(t_philo *philo, t_fork *forks, int nb_philo)
{
	int	i;
	(void)philo;
	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&forks[i].m_fork);
		forks[i].status = IS_FREE;
		pthread_mutex_unlock(&forks[i].m_fork);
		i++;
	}
/*	i = 0;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].m_status);
		philo[i].status = IS_THINKING;
		pthread_mutex_unlock(&philo[i].m_status);
		i += 2;
	}
	ms_sleep(1);
	i = 1;
	while (i < nb_philo)
	{
		pthread_mutex_lock(&philo[i].m_status);
		philo[i].status = IS_THINKING;
		pthread_mutex_unlock(&philo[i].m_status);
		i += 2;
	}*/
	ms_sleep(1);
}
/*
static void	stop_simulation(t_philo *philo, int nb_philo)
{
	while (nb_philo--)
	{
		pthread_mutex_lock(&philo[nb_philo].m_status);
		philo[nb_philo].status = IS_DEAD;
		pthread_mutex_unlock(&philo[nb_philo].m_status);
	}
}
*/
static int	is_dead_philo(t_philo *philo, int nb_philo, t_ms time_to_die)
{
	struct timeval	now;
	t_ms			last_eat;

	gettimeofday(&now, NULL);
	while (nb_philo--)
	{
		last_eat = get_time_in_ms(philo[nb_philo].last_eat);
		if (last_eat > 0
			&& get_diff_time_ms(philo[nb_philo].last_eat, now) > time_to_die)
			return (nb_philo);
	}
	return (-1);
}

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

void	start_simulation(t_dinner_table *table, t_rules *rules)
{
	int		i;
	int		nb_philo;
	int		nb_philo_dead;
	t_philo	*philo;

	nb_philo = table->nb_philo;
	philo = table->philos;
	make_it_start(philo, table->forks, nb_philo);
	ms_sleep(10);
	while (check_max_eat(philo, nb_philo, rules->nb_meal) == FAILLURE)
	{
		i = 0;
		while (i < nb_philo)
		{
			nb_philo_dead = is_dead_philo(philo, nb_philo, rules->time_to_die);
			if (nb_philo_dead != -1)
			{
				print_status(philo + nb_philo_dead, IS_DEAD, rules);
				//stop_simulation(philo, nb_philo);
				return ;
			}	
			i++;
		}
	}
}

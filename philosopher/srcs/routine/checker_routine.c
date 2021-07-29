/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:58:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 16:36:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** For start simulation make fork in order
**		for philo impair 
**		sleep(2ms)
**		for philo pair
**	else they can take each a fork and nobody can eat
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

static void	make_it_start(int nb_philo, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (!(i % 2))
		{
			pthread_mutex_lock(&philo[i].m_status);
			philo[i].status = IS_THINKING;
			pthread_mutex_unlock(&philo[i].m_status);
		}
		i++;
	}
	ms_sleep(1, NULL);
	i = 0;
	while (i < nb_philo)
	{
		if (i % 2)
		{
			pthread_mutex_lock(&philo[i].m_status);
			philo[i].status = IS_THINKING;
			pthread_mutex_unlock(&philo[i].m_status);
		}
		i++;
	}
}

static int	is_dead_philo(t_philo *philo, int nb_philo, t_ms time_to_die)
{
	struct timeval	now;
	t_ms			last_eat;

	while (nb_philo--)
	{
		gettimeofday(&now, NULL);
		last_eat = get_diff_time_ms(philo[nb_philo].last_eat, now);
		if (last_eat > 0 && last_eat > time_to_die)
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
	init_the_begin_time(rules, philo, nb_philo);
	make_it_start(nb_philo, philo);
	ms_sleep(1, NULL);
	while (check_max_eat(philo, nb_philo, rules->nb_meal) == FAILLURE)
	{
		i = 0;
		while (i < nb_philo)
		{
			nb_philo_dead = is_dead_philo(philo, nb_philo, rules->time_to_die);
			if (nb_philo_dead != -1)
			{
				print_status(philo + nb_philo_dead, IS_DEAD, rules);
				return ;
			}	
			i++;
		}
		ms_sleep(1, NULL);
	}
}

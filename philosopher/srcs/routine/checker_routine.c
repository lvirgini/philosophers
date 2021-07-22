/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 15:58:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 21:37:14 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	make_it_start(t_philo	*philo, t_fork *forks, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		forks[i].status = IS_FREE;
		i++;
	}
	i = 0;
	while (i < nb_philo)
	{
		philo[i].status = IS_THINKING;
		i += 2;
	}
	ft_sleep(10);
	i = 1;
	while (i < nb_philo)
	{
		philo[i].status = IS_THINKING;
		i += 2;
	}

}

static void	stop_simulation(t_philo *philo, int nb_philo)
{
	while (nb_philo--)
		philo[nb_philo].status = IS_DEAD;
}

static int	is_dead_philo(t_philo *philo, int nb_philo, t_ms time_to_die)
{
	struct timeval	now;
	t_ms			last_eat;
	
	gettimeofday(&now, NULL);
	while (nb_philo--)
	{
	
	//	printf("%ld, %ld\n", get_time_in_ms(philo[nb_philo].last_eat), time_to_die);
	last_eat = get_time_in_ms(philo[nb_philo].last_eat);
		if (last_eat > 0 
		&& get_time_in_ms(now) - last_eat >= time_to_die)
			return (nb_philo);
	//printf("%ld\n",  get_time_in_ms(now) - last_eat);
	}
	return (-1);
}

void	start_simulation(t_dinner_table *table, t_rules *rules)
{
	int		i;
	int		nb_philo;
	int		nb_philo_dead;
	t_philo *philo;

	nb_philo = table->nb_philo;
	philo = table->philos;
	
	make_it_start(philo, table->forks, nb_philo);
	while (1)
	{
		i = 0;
		while (i < nb_philo)
		{
			nb_philo_dead = is_dead_philo(philo, nb_philo, rules->time_to_die);
			if (nb_philo_dead != -1)
			{
				print_status(philo[nb_philo_dead].id, IS_DEAD, rules->begin);
				stop_simulation(philo, nb_philo);
				return ;
			}	
			i++;
		}
	}
}
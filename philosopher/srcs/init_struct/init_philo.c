/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:48:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 18:53:50 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static t_philo	init_philo( int id, t_rules *rules, t_fork *left, t_fork *right)
{
	t_philo		philo;

	philo.id = id;
	philo.fork_left = left;
	philo.fork_right = right;
	philo.status = IS_DEAD;
	philo.rules = rules;
	philo.last_eat.tv_sec = 0;
	philo.last_eat.tv_usec = 0;
	philo.nb_eat = 0;
	philo.thrd_id = 0;
	return (philo);
}

t_philo	*malloc_philos(int nb_philo, t_rules *rules, t_fork *forks)
{
	t_philo	*philos;
	int		i;

	philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo + 1);
	if (!philos)
		return (NULL);
	if (nb_philo == 1)
		philos[0] = init_philo(1, rules, NULL, forks);
	else
	{
		philos[0] = init_philo(1, rules, forks + nb_philo - 1, forks);
		printf("INIT PHILO = ID = %d\n\tleft = %p\n\tright = %p\n", (philos)->id, (philos)->fork_left, (philos)->fork_right);

		i = 1;
		while (i < nb_philo)
		{
			philos[i] = init_philo((i + 1), rules, (forks + i - 1), (forks + i));
			printf("INIT PHILO = ID = %d\n\tleft = %p\n\tright = %p\n", (philos + i)->id, (philos + i)->fork_left, (philos + i)->fork_right);
			i++;
		}
	}
	return (philos);
}

void	free_philos(t_philo *philo, int nb_philo)
{
	if (philo)
	{
			free(philo);
			(void)nb_philo;
	}
}
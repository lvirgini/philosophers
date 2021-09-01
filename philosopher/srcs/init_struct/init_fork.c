/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:24:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/01 10:47:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*malloc_forks(int nb_philo)
{
	t_fork	*forks;
	int		i;

	forks = (t_fork *)malloc(sizeof(t_fork) * nb_philo);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < nb_philo)
	{
		if (pthread_mutex_init(&forks[i].m_fork, NULL) != 0)
		{
			free_forks(forks, i);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

void	free_forks(t_fork *forks, int nb_philo)
{
	if (forks)
	{
		while (nb_philo--)
			pthread_mutex_destroy(&forks[nb_philo].m_fork);
		free(forks);
	}
}

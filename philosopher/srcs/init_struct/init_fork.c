/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:24:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 13:38:13 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*malloc_forks(int nb_philo)
{
	t_fork	*forks;

	forks = (t_fork *)malloc(sizeof(t_fork) * nb_philo);
	if (!forks)
		return (NULL);
	while (nb_philo--)
	{
		forks[nb_philo].status = IS_FREE;
		pthread_mutex_init(&forks[nb_philo].m_fork, NULL);
	}
	return (forks);
}

void	free_forks(t_fork *forks, int nb_philo)
{
	if (forks)
	{
		while (nb_philo--)
			pthread_mutex_destroy(&(forks + nb_philo)->m_fork);
		free(forks);
	}
}

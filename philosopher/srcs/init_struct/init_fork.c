/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:24:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 23:27:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_fork	*init_forks(int nb_philo)
{
	t_fork	*forks;

	forks = (t_fork *)malloc(sizeof(t_forks) * nb_philo));
	if (!forks)
		return (NULL);
	while (nb_philo--)
		forks[nb_philo].status = IS_FREE;
	return (forks);
}

void	free_forks(t_forks *forks, int nb_philo)
{
	if (forks)
	{
		while (nb_philo--)
			free(fork + nb_philo);
	}
}

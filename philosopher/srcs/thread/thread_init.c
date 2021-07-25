/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:16:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:16:52 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	create_philo_thread(t_philo	*philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(philo + i)->thrd_id, NULL, &routine,
				philo + i) != 0)
			return (FAILLURE);
		i++;
	}
	return (SUCCESS);
}

void	join_philo_thread(t_philo *philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		pthread_join((philo + i)->thrd_id, NULL);
		i++;
	}
}

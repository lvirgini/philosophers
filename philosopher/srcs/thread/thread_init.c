/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:16:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/23 17:14:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
/*
void	*test(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;

	while (philo->status != IS_EATING)
		;

	printf("philo n°%d\n", philo->id);
	return (NULL);
}*/

int		create_philo_thread(t_philo	*philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		printf("philo ID = %d\n", (philo + i)->id);
		if (pthread_create(&(philo + i)->thrd_id, NULL, &routine,
				philo + i) != 0)
			return (FAILLURE);
		pthread_detach((philo + i)->thrd_id);
		i++;
	}
/*	i = 0;
	while (i < nb_philo)
	{
		philo[i].status = IS_THINKING;
		i++;
	}
	while (i < nb_philo)
	{
		pthread_join((philo + i)->thrd_id, NULL);
		i++;
	}*/
	return (SUCCESS);
}

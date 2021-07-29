/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:16:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 14:04:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	make_it_stop(t_rules *rules)
{
	pthread_mutex_lock(&rules->m_print);
	rules->able_to_write = false;
	pthread_mutex_unlock(&rules->m_print);
	ms_sleep(20, NULL);
}

int	create_philo_thread(t_philo	*philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		if (pthread_create(&(philo + i)->thrd_id, NULL, &routine,
				philo + i) != 0)
		{
			make_it_stop(philo->rules);
			return (FAILLURE);
		}	
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
		if (philo->thrd_id != 0)
			pthread_join((philo + i)->thrd_id, NULL);
		i++;
	}
}

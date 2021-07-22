/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 15:15:27 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 21:03:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	drop_fork(t_fork *fork)
{
	fork->status = IS_FREE;


}
int		take_fork(t_fork *fork)
{
	if (fork)
	{
		pthread_mutex_lock(&(fork->m_fork));
		if (fork->status == IS_FREE)
		{
			fork->status = IS_TAKEN;
			pthread_mutex_unlock(&(fork->m_fork));
			return(SUCCESS);
		}	
		pthread_mutex_unlock(&(fork->m_fork));
	}
	return (FAILLURE);
}


void	*routine(void *philosopher)
{
	t_philo			*philo;
	struct timeval	begin;
	
	philo = (t_philo *)philosopher;
	begin = philo->rules->begin;
	
	//	printf("philo n°%d\n", philo->id);
		//while (philo->nb_eat < philo->rules->nb_meal)
	while (philo->status == IS_DEAD)
		ft_sleep(100);
	
	while(philo->status != IS_DEAD)
	{
		printf("%d\n", philo->status);
		if (philo->status == IS_THINKING)
		{
			if (take_fork(philo->fork_right) == SUCCESS)
			{
				if (take_fork(philo->fork_left) == SUCCESS)
				{
					print_status(philo->id, TAKEN_FORK, begin);
					print_status(philo->id, TAKEN_FORK, begin);
					print_status(philo->id, IS_EATING, begin);
					philo->status = IS_EATING;
					philo->nb_eat += 1;
					gettimeofday(&(philo)->last_eat, NULL);
					printf("%ld EATING PHILO\n", get_time_in_ms(philo->last_eat));
					ft_sleep(philo->rules->time_to_eat);
					drop_fork(philo->fork_right);
					drop_fork(philo->fork_left);
				}
				else
					drop_fork(philo->fork_right);

			}
		}
		else if (philo->status == IS_EATING)
		{
			philo->status = IS_SLEEPING;
			print_status(philo->id, IS_SLEEPING, begin);
			ft_sleep(philo->rules->time_to_sleep);
		}
		else if (philo->status == IS_SLEEPING)
		{
			philo->status = IS_THINKING;
			print_status(philo->id, IS_THINKING, begin);
		}
	}
	return (NULL);
}

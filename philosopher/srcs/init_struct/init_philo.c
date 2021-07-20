/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:48:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 17:19:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philo *init_philo(t_fork	*left, t_fork *right, int id, t_rules *rules)
{
	t_philo *philo;

	philo = (t_philo *)malloc(sizeof(t_philo));
	if (philo == NULL)
		return (NULL);
	philo->id = id;
	philo->fork_left = left;
	philo->fork_right = right;
	philo->status = IS_THINKING;
	philo->rules = rules;
	philo->last_eat.tv_sec = 0;
	philo->last_eat.tv_usec = 0;
	philo->nb_eat = 0;
	philo->thrd_id = 0;
	return (philo);
}

void	free_philos(t_philo *philo, int nb_philo)
{
	if (philo)
	{
		free(philo->rules);
		while (nb_philo--)
			free(philo + nb_philo);
		free(philo);
	}
}

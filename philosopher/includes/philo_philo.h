/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:45:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/25 14:50:22 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PHILO_H
# define PHILO_PHILO_H

# include "philosophers.h"

/*
** fork left	= &fork right philo[n - 1]
** fork right	= &fork left philo [n + 1]
*/

typedef struct s_philo
{
	int				id;
	int				status;
	int				nb_eat;
	struct timeval	last_eat;
	t_rules			*rules;
	t_fork			*fork_right;
	t_fork			*fork_left;
	pthread_t		thrd_id;
	pthread_mutex_t	m_status;
}	t_philo;

t_philo		*malloc_philos(int nb_philo, t_rules *rules, t_fork *forks);
void		free_philos(t_philo *philo, int nb_philo);
int			create_philo_thread(t_philo	*philo);
void		join_philo_thread(t_philo *philo, int nb_philo);

#endif

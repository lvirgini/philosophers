/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:45:40 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 00:12:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_PHILO_H
# define PHILO_PHILO_H

# include "philosophers.h"

typedef struct s_philo t_philo;

struct s_philo
{
	int				id;
	int				status;
	int				nb_eat;
	struct timeval	last_eat;
	t_rules			*rules;
	t_fork			*fork_right; // adresse identique a philo + 1 fork left
	t_fork			*fork_left;	 // adresse identique a philo - 1 fork right
	pthread_t		thrd_id;
};

t_philo 	*init_philo(int	*fork_left);
void		free_philos(t_philo *philo, int nb_philo);

#endif

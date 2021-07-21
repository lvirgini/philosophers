/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:23:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/21 14:29:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FORK_H
# define PHILO_FORK_H

# include "philosophers.h"

/*
**   forks[i].status = x;
**	(fork + i)->status = x;
*/

enum	e_fork
{
	IS_FREE,
	IS_TAKEN,
};

typedef struct s_fork
{
	int				status;
	pthread_mutex_t	m_fork;
}	t_fork;

t_fork	*malloc_forks(int nb_philo);
void	free_forks(t_fork *forks, int nb_philo);

#endif

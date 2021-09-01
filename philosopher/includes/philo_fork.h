/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_fork.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 23:23:00 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/01 10:47:00 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_FORK_H
# define PHILO_FORK_H

# include "philosophers.h"

typedef struct s_fork
{
	pthread_mutex_t	m_fork;
}	t_fork;

t_fork	*malloc_forks(int nb_philo);
void	free_forks(t_fork *forks, int nb_philo);

#endif

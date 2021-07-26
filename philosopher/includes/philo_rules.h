/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rules.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:59:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 15:35:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_RULES_H
# define PHILO_RULES_H

# include "philosophers.h"

typedef struct s_rules
{
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	t_ms			time_to_die;
	int				nb_meal;
	int				able_to_write;
	struct timeval	begin;
	pthread_mutex_t	m_print;
}t_rules;

int		get_rules(int argc, char **argv, t_rules *rules);
void	destroy_rules(t_rules *rules);

#endif

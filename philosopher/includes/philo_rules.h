/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_rules.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 11:59:12 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/24 12:17:01 by lvirgini         ###   ########.fr       */
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
}t_rules;

int		get_rules(int argc, char **argv, t_rules *rules);

#endif

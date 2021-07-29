/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rules.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:17:16 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 17:06:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_rules(t_rules *rules)
{
	if (rules->time_to_eat < 0 || rules->time_to_sleep < 0
		|| rules->time_to_die < 0)
	{
		pthread_mutex_destroy(&rules->m_print);
		return (FAILLURE);
	}
	return (SUCCESS);
}

int	get_rules(int argc, char **argv, t_rules *rules)
{
	int		nb_meal;

	nb_meal = -1;
	if (argc == 6)
	{
		nb_meal = (int)mini_atoi(argv[5]);
		if (nb_meal < 1)
			return (FAILLURE);
	}	
	rules->time_to_die = mini_atoi(argv[2]);
	rules->time_to_eat = mini_atoi(argv[3]);
	rules->time_to_sleep = mini_atoi(argv[4]);
	rules->nb_meal = nb_meal;
	rules->able_to_write = true;
	if (pthread_mutex_init(&rules->m_print, NULL) != 0)
		return (FAILLURE);
	return (check_rules(rules));
}

void	destroy_rules(t_rules *rules)
{
	if (rules)
		pthread_mutex_destroy(&rules->m_print);
}

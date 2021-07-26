/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 14:20:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_table(char **argv, t_dinner_table *table, t_rules *rules)
{
	int		nb_philo;

	nb_philo = (int)mini_atoi(argv[1]);
	if (nb_philo < 1)
		return (FAILLURE);
	table->forks = NULL;
	table->philos = NULL;
	table->rules = rules;
	table->nb_philo = nb_philo;
	return (SUCCESS);
}

/*
** after join all thread we can destroy all mutex and free all malloc
*/

void	free_all_table(t_dinner_table *table)
{
	if (table)
	{
		if (table->philos)
			free_philos(table->philos, table->nb_philo);
		if (table->forks)
			free_forks(table->forks, table->nb_philo);
		if (table->rules)
			destroy_rules(table->rules);
	}
}

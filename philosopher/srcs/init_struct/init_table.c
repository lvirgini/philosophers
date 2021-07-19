/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:48:03 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 00:12:08 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_dinner_table 	*init_dinner_table(int	nb_philo)
{
	t_dinner_table	*table;
	t_philo			*philos;
	t_fork			*forks;

	table = (t_dinner_table *)malloc(sizeof(t_dinner_table));
	if (!table)
		return (NULL);
	ft_memset(table, 0, sizeof(t_table));
	table->philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * nb_philo);
	if (!table->forks || !table->philo)
		return (philo_error(ERR_MALLOC, table));
	table->all_alive = true;
	table->if_all_eat = false;
	return (table);
}

void	free_table(t_dinner_table *table)
{
	if (table)
	{
		if (table->philosophers)
			free_philos(table->philos);
		if (table->forks)
			free_forks(table->forks);
		free(table);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:18:32 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 19:18:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_table(char **argv, t_dinner_table *table)
{
	int		nb_philo;

	nb_philo = (int)mini_atoi(argv[1]);
	if (nb_philo < 1)
		return (FAILLURE);
	table->forks = NULL;
	table->philos = NULL;
	table->all_alive = true;
	table->if_all_eat = false;
	table->nb_philo = nb_philo;
	return (SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:33:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** check entrée : si tout conforme
** initialise les philosophe
** creation de la simulation
** check si il y a un mort
** fin de la simulation
*/

int	main(int argc, char **argv)
{
	t_dinner_table	table;
	t_rules			rules;

	if (parse_args(argc, argv, &table, &rules))
		return (EXIT_FAILURE);
	if (rules.nb_meal == 0)
	{
		free_all_table(&table);
		return (EXIT_SUCCESS);
	}
	if (create_philo_thread(table.philos, table.nb_philo) == FAILLURE)
		return (philo_error(ERR_THREAD_INIT, &table));
	start_simulation(&table, &rules);
	join_philo_thread(table.philos, table.nb_philo);
	free_all_table(&table);
	return (EXIT_SUCCESS);
}

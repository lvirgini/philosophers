/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 14:45:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** parsing args
** create all structures and needed
** start simulation
** join all thread
** free all malloc
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

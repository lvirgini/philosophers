/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/25 15:19:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** parsing args
** create all structures and needed
** start simulation
** join all threads
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
	if (start_simulation(&table, &rules, table.philos, table.nb_philo)
		== FAILLURE)
		return (EXIT_FAILURE);
	free_all_table(&table);
	return (EXIT_SUCCESS);
}

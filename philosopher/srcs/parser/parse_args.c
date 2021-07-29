/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:43:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 17:32:25 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** init rules and table structure
** malloc and init fork
** malloc and init philo
*/

int	parse_args(int argc, char **argv, t_dinner_table *table, t_rules *rules)
{
	if (argc < 4 || argc > 6
		|| get_rules(argc, argv, rules) == FAILLURE
		|| get_table(argv, table, rules) == FAILLURE)
		return (philo_error(ERR_ARG, NULL));
	table->forks = malloc_forks(table->nb_philo);
	if (!table->forks)
		return (philo_error(ERR_ARG, table));
	table->philos = malloc_philos(table->nb_philo, rules, table->forks);
	if (!table->philos)
		return (philo_error(ERR_ARG, table));
	return (SUCCESS);
}

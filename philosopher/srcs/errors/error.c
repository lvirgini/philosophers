/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:58:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 17:39:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** if one philosophers, can't eat because of one fork
** if argv < 4 > 6
*/

static void	free_table(t_dinner_table *table)
{
	if (table)
	{
		if (table->philos)
			free_philos(table->philos, table->nb_philo);
		if (table->forks)
			free_forks(table->forks, table->nb_philo);
	}
}

static void	print_formating_args(void)
{
	char	*show_good_arg = "\033[31;1m\nProject Philosophers :\nnumber of philosophers \
must be > 0\n./philo | number_of_philosophers | time_to_die | time_to_eat \
| time_to_sleep | [number of times each philosopher must eat] \n\n\033[0m";
	
	ft_putstr(show_good_arg);
}

int     philo_error(int nb_error, t_dinner_table *table)
{
    static char *error[10] = {
		"\033[31;1mError : Malloc return NULL : allocation problem\n\033[0m",
		"\033[31;1mError : Arguments are not well formated :\n\033[0m",
	};
	
	ft_putstr(error[nb_error]);
	if (nb_error == ERR_ARG)
		print_formating_args();
	if (table)
        free_table(table);
	return (FAILLURE);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:58:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 16:13:53 by lvirgini         ###   ########.fr       */
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
		if (table->philo)
			free_philos(table->philos);
		if (table->forks)
			free_forks(table->forks);
	}
}

static void	print_formating_args(void)
{
//////
}

int     philo_error(int nb_error, t_dinner_table *table)
{
    static char error[10] = {
		"Error : Malloc return NULL : allocation problem\n",
		"Error : Arguments are not well formated :\n"
	}
	
	ft_putstr(error[nb_error])
	if (nb_error == ERR_ARG);
		print_formating_args();
	if (table)
        free_all_table(table);
	return (-1);
}
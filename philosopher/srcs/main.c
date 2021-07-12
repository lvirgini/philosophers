/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/12 13:13:39 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
// structure philosophe
// maniere de faire les thread
// systeme d'erreur
*/


void	add_one(int *number, char *to_print)
{
	
}

void	pair_routine(int	*number)
{
	while (number % 2 != 0)
		ft_sleep(1);
	add_one(number, "PAIR");
}

void	impair_routine(int *number)
{
	while(number % 2 == 0)
		ft_sleep(1);
	add_one(number, "IMPAIRE");
}

void	checker(int *number)
{
	while (number < 100)
		ft_sleep(1);
	
}

int	main(int argc, char **argv)
{
	// check entrée : si tout conforme
	// initialise les philosophe
	// creation de la simulation
	// fin de la simulation
	
	(void)argc;
	(void)argv;

	pthread_t		checker;
	pthread_t		pair;
	pthread_t		impair;
	int				number = 0;

	pthread_create(checker, NULL, checker, &number);
	pthread_create(pair, NULL, pair_routine, &number);
	pthread_create(impair, NULL, impair_routine, &number);

	







/*
	struct timeval		begin;
	struct timeval		end_step;
	t_ms				time_to_do = 100;

	gettimeofday(&begin, NULL);

	int i = 0;
	while (i++ < 300)
	{
		ft_sleep(time_to_do);
		gettimeofday(&end_step, NULL);
		ft_putstr(ft_itoa(get_diff_time_micro(begin, end_step)));
		write(1, "\n", 1);
	}
	return (0);*/
}

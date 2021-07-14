/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/14 21:45:11 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
// structure philosophe
// maniere de faire les thread
// systeme d'erreur
*/

typedef struct number
{
	int					number;
	int					locked_number;
	pthread_mutex_t		mutex_nb;
}number;


void	add_one(number *nb, char *to_print)
{
	nb->number = nb->number + 1;
	printf("number : %d\t%s\n", nb->number, to_print);
}

void	*pair_routine(void *n)
{
	number *nb = (number *)n;
	//while(1)
	if (1)
	{		
		if (nb->locked_number == IS_FREE)
		{
			pthread_mutex_lock(&nb->mutex_nb);
			nb->locked_number = IS_TAKEN;
			if (nb->number % 2 == 0)
				add_one(nb, "PAIR");
			nb->locked_number = IS_FREE;
			pthread_mutex_unlock(&nb->mutex_nb);	
		}
		ft_sleep(10);
	}
	return (NULL);
}

void	*impair_routine(void *n)
{
	number *nb = (number *)n;
	//while(1)
	if(1) 
	{
		if (nb->locked_number == IS_FREE)
		{
			pthread_mutex_lock(&nb->mutex_nb);
			nb->locked_number = IS_TAKEN;
			if (nb->number % 2 != 0)
				add_one(nb, "IMPAIRE");
			nb->locked_number = IS_FREE;
			pthread_mutex_unlock(&nb->mutex_nb);
		}
		ft_sleep(10);
	}
	return (NULL);
}

void	*checker_routine(void *n)
{
	number *nb = (number *)n;
	while (1)
	{
		pthread_mutex_lock(&nb->mutex_nb);
		nb->locked_number = IS_TAKEN;	
		if (nb->number >= 3)
		{
			pthread_mutex_unlock(&nb->mutex_nb);
			return (NULL);
		}
		nb->locked_number = IS_FREE;	
		pthread_mutex_unlock(&nb->mutex_nb);
	}
}

/*
** check entrée : si tout conforme
** initialise les philosophe
** creation de la simulation
** fin de la simulation
*/

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;

	pthread_t		checker;
	pthread_t		pair;
	pthread_t		impair;


	number	nb;
	nb.number = 0;
	nb.locked_number = IS_FREE;
	pthread_mutex_init(&(nb.mutex_nb), NULL);

	if (pthread_create(&pair, NULL, pair_routine, &nb) != 0)
		return (EXIT_FAILURE);
	pthread_detach(pair);
	if (pthread_create(&impair, NULL, impair_routine, &nb) != 0)
		return (EXIT_FAILURE);
	pthread_detach(impair);
	if (pthread_create(&checker, NULL, checker_routine, &nb) != 0)
		return (EXIT_FAILURE);
	pthread_join(checker, NULL);

	pthread_mutex_destroy(&nb.mutex_nb);

	return (0);
/*
	struct timeval		begin;
	struct timeval		end_step;
	t_ms				time_to_do = 500;

	gettimeofday(&begin, NULL);

	int i = 0;
	while (i++ < 300)
	{
		//ft_sleep(time_to_do);
		usleep(time_to_do * 1000);
		gettimeofday(&end_step, NULL);
		ft_putstr(ft_itoa(get_diff_time_ms(begin, end_step)));
		write(1, "\n", 1);
	}
	return (0);*/
}


/*


routine : 

while is_not_dead

	- mutex lock fork -
	check_fork
	if fork free take them 
		start to eat (time to eat)
		free fork
		- mutex unlock fork -
		start to sleep(time to sleep)
	else
		-mutex unlock fork -




check dead : 



*/
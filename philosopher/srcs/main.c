/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/08 11:36:56 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
// structure philosophe
// maniere de faire les thread
// systeme d'erreur


// si impaire (3) == 3 groupe
//		1  		2  		last
//		mange 	wait	wait
//		sleep	mange	wait
//		wait	sleep	mange

si impare 5 et +  == 3 groupe

		1 et 3 same
		2 et 4 same
		5 

		1		2		3		4		5

si pair (2) == 2 groupe

si pair 4++ == 2 groupe



		1 et 3 et ++ same
		1		2		3		last 
		mange	wait	mange	wait
		

*/		

/*
int		pair_routine(int	*number)
{

}*/


int	main(int argc, char **argv)
{
	// check entrée : si tout conforme
	// initialise les philosophe
	// creation de la simulation
	// fin de la simulation
	(void)argc;
	(void)argv;


	struct timeval		begin;
	struct timeval		end_step;

	t_ms				time_to_do = 100;

	gettimeofday(&begin, NULL);

	// prevoir le temps des actions et attendre tant que temps actuel < temps necessaire

	int i = 0;
	while (i++ < 300)
	{
		ft_sleep(time_to_do);
		gettimeofday(&end_step, NULL);
		ft_putstr(ft_itoa(get_diff_time_micro(begin, end_step)));
		write(1, "\n", 1);
	}
	return (0);
}


/*
int main(void)
{

// TESTING GETTIMEOFDAY : 


	struct timeval		begin;
	struct timeval		begin_step;
	struct timeval		end_step;

	t_ms				time_actual;
	t_ms				time_to_end;
	t_ms				time_to_do = 200;

	gettimeofday(&begin, NULL);

	// prevoir le temps des actions et attendre tant que temps actuel < temps necessaire

	int i = 0;
	while (i++ < 300)
	{
		end_step.tv_sec = 0;
		end_step.tv_usec = 0;
		time_actual = 0;
		
		gettimeofday(&begin_step, NULL);
		time_to_end = get_time_in_micro(begin) + ms_to_micro(time_to_do);

		while (time_actual < time_to_end)
		{
			usleep(100);
			gettimeofday(&end_step, NULL);
			time_actual = get_time_in_ms(begin) + get_time_in_ms(end_step);
		}

		ft_putstr(ft_itoa(get_diff_time_ms(begin, end_step)));
		write(1, "\n", 1);
	}
	return (0);
}*/

		/*end_step.tv_sec = 0;
		end_step.tv_usec = 0;
		time_actual = 0;
		
		gettimeofday(&begin_step, NULL);
		time_to_end = get_time_in_ms(begin) + get_time_in_ms(begin_step) + time_to_do;

		while (time_actual < time_to_end)
		{
			usleep(100);
			gettimeofday(&end_step, NULL);
			time_actual = get_time_in_ms(begin) + get_time_in_ms(end_step);
		}

		ft_putstr(ft_itoa(get_diff_time_ms(begin, end_step)));
		write(1, "\n", 1);*/




				/*struct timeval		begin_step;
		end_step.tv_sec = 0;
		end_step.tv_usec = 0;
		t_ms	time_actual = 0;
		t_ms	time_to_end = 0;
		
		gettimeofday(&begin_step, NULL);
		time_to_end = get_time_in_ms(begin) + get_time_in_ms(begin_step) + time_to_do;

		while (time_actual < time_to_end)
		{
			usleep(100);
			gettimeofday(&end_step, NULL);
			time_actual = get_time_in_ms(begin) + get_time_in_ms(end_step);
		}

		ft_putstr(ft_itoa(get_diff_time_ms(begin, end_step)));
		write(1, "\n", 1);*/
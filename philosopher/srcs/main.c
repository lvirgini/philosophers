/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 21:17:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 20:56:18 by lvirgini         ###   ########.fr       */
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
		return(EXIT_FAILURE);
	if (rules.nb_meal == 0)
	{
		free_all_table(&table);
		return (SUCCESS);
	}
	if (create_philo_thread(table.philos, table.nb_philo) == FAILLURE)
		return (philo_error(ERR_THREAD_INIT, &table));
	start_simulation(&table, &rules);
	free_all_table(&table);
	return (EXIT_SUCCESS);
}




	/*number	nb;
	
	nb.number = 0;
	nb.end = 0;

	
	pthread_mutex_init(&(nb.mutex_nb), NULL);

	if (pthread_create(&pair, NULL, pair_routine, &nb) != 0)
		return (EXIT_FAILURE);
	pthread_detach(pair);
	if (pthread_create(&impair, NULL, impair_routine, &nb) != 0)
		return (EXIT_FAILURE);
	pthread_detach(impair);
	
	while (1)
	{
		pthread_mutex_lock(&nb.mutex_nb);
		if (nb.number >= 10)
		{
			nb.end = 1;
			ft_sleep(100);
			pthread_mutex_unlock(&nb.mutex_nb);
		 	pthread_mutex_destroy(&nb.mutex_nb);
			return (0);
		}
		pthread_mutex_unlock(&nb.mutex_nb);
	}*/

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


/*


void	*test(void *philosopher)
{
	t_philo	*philo;

	philo = (t_philo *)philosopher;

	while (philo->status != IS_EATING)
		;

	printf("philo n°%d\n", philo->id);
	return (NULL);
}


int		create_philo_thread(t_philo	*philo, int nb_philo)
{
	int	i;

	i = 0;
	while (i < nb_philo)
	{
		printf("philo ID = %d\n", (philo + i)->id);
		if (pthread_create(&(philo + i)->thrd_id, NULL, &test, philo + i) != 0)
			return (FAILLURE);
		pthread_detach((philo + i)->thrd_id);
		i++;
	}

	ft_sleep(1000);
	i = 0;
	while (i < nb_philo)
	{
		philo[i].status = IS_EATING;
		//ft_sleep(1000);
		//pthread_join((philo + i)->thrd_id, NULL);
		i++;
	}
		return (SUCCESS);
}*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/23 17:32:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(int philo_id, int status, struct timeval begin)
{
	static			mutex;
	struct timeval	time;
	static char		*str_status[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
	};
	if begin == NULL
		init mutex // initialise une seule fois le mutex
	//pthread_mutex_init()
	gettimeofday(&time, NULL);
	printf("%ld ms\t%d %s\n",get_diff_time_ms(begin, time), philo_id, str_status[status]);
}

/// faire une static dans la structure 
// mettre la static a 1 si 1 mort et ne pas rentrer dans la fonction print

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 19:48:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(int philo_id, int status, struct timeval begin)
{
	struct timeval	time;
	static char		*str_status[5] = {
		"has taken a fork",
		"is eating",
		"is sleeping",
		"is thinking",
		"died",
	};

	gettimeofday(&time, NULL);
	printf("%ld ms\t%d %s\n",get_diff_time_ms(begin, time), philo_id, str_status[status]);
}

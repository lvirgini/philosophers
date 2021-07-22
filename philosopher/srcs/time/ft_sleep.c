/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:02:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/14 19:16:26 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** micro usleep for more precision.
** get time ending and stop when actual time is egal.
*/

void	ft_sleep(t_ms time_to_wait)
{
	struct timeval	time_actual;
	t_ms			time_to_stop;

	gettimeofday(&time_actual, NULL);
	time_to_stop = get_time_in_ms(time_actual) + time_to_wait;
	while (get_time_in_ms(time_actual) < time_to_stop)
	{
		usleep(100);
		gettimeofday(&time_actual, NULL);
	}
}
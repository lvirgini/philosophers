/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:02:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/08 11:41:34 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** micro usleep for more precision.
** get time ending and stop when actual time is egal.
*/

void	ft_sleep(t_ms time_to_wait)
{
	struct timeval	actual;
	t_ms			time_to_end;
//	struct timeval time_to_end2;

	gettimeofday(&actual, NULL);
	time_to_end = get_time_in_ms(actual) + time_to_wait;
	while (get_time_in_ms(actual) < time_to_end)
	{
		usleep(10);
		gettimeofday(&actual, NULL);
	}
/*
	while (get_diff_time_micro(time_to_end2, actual) > 0)
	{
		usleep(1);
		gettimeofday(&actual, NULL);
	}*/
}

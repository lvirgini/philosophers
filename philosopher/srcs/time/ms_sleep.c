/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:02:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/09/01 16:37:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** micro usleep for more precision.
** get time ending and stop when actual time is egal.
*/

void	ms_sleep(t_ms time_to_wait, t_rules *rules)
{
	struct timeval	time_actual;
	t_ms			time_to_stop;
	int				count_checker;

	count_checker = 0;
	gettimeofday(&time_actual, NULL);
	time_to_stop = get_time_in_ms(time_actual) + (time_to_wait);
	while (get_time_in_ms(time_actual) - time_to_stop < 0)
	{
		count_checker++;
		if (count_checker == 5000)
		{
			if (can_write(rules) == false)
				return ;
			count_checker = 0;
		}
		usleep(100);
		gettimeofday(&time_actual, NULL);
	}
}

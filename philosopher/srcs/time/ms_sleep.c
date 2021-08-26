/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 19:02:22 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/26 14:12:47 by lvirgini         ###   ########.fr       */
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
	time_to_stop = get_time_in_ms(time_actual) + time_to_wait;
	while (get_time_in_ms(time_actual) < time_to_stop)
	{
		count_checker++;
		if (count_checker == 50)
		{
			if (can_write(rules) == false)
				return ;
			count_checker = 0;
		}
		usleep(10);
		gettimeofday(&time_actual, NULL);
	}
}

static suseconds_t	get_time_in_us(struct timeval time)
{
	return (second_to_ms(time.tv_sec) * 1000 + time.tv_usec);
}

void	ft_usleep(suseconds_t time_to_wait)
{
	struct timeval	time_actual;
	t_ms			time_to_stop;

	gettimeofday(&time_actual, NULL);
	time_to_stop = get_time_in_us(time_actual) + time_to_wait;
	while (get_time_in_us(time_actual) < time_to_stop)
	{
		usleep(1);
		gettimeofday(&time_actual, NULL);
	}
}

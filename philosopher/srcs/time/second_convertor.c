/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_convertor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:26:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/07 18:49:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** conversion time
*/

t_ms	micro_to_ms(suseconds_t micro)
{
	return (micro / 1000.0);
}

t_ms	second_to_ms(time_t second)
{
	return (second * 1000);
}

suseconds_t	ms_to_micro(t_ms ms)
{
	return (ms * 1000);
}

t_ms	get_time_in_ms(struct timeval time) //
{
	return (second_to_ms(time.tv_sec) + micro_to_ms(time.tv_usec));
}

suseconds_t	get_time_in_micro(struct timeval time) //
{
	return (ms_to_micro(second_to_ms(time.tv_sec)) + time.tv_usec);
}

struct timeval	add_timeval(struct timeval t1, struct timeval t2)
{
	struct timeval res;

	res.tv_sec = t1.tv_sec + t2.tv_sec;
	res.tv_usec = t1.tv_usec + t2.tv_usec;
	return (res);
	//return (second_to_ms(t1.tv_sec + t2.tv_sec) + micro_to_ms(t1.tv_usec + t2.tv_usec));
}
/*
int	ft_sleep(t_ms time_to_wait)
{
	struct timeval	actual;
	t_ms			time_to_end;

	gettimeofday(&actual, NULL);
	time_to_end = get_time_in_ms(actual) + time_to_wait;
	while (get_time_in_ms(actual) < time_to_end)
	{
		usleep(100);
		gettimeofday(&actual, NULL);
	}
	return (success);
}*/

int	ft_sleep(t_ms time_to_wait, struct timeval begin)
{
	struct timeval	actual;
	suseconds_t		time_to_end;

	(void)begin;
	gettimeofday(&actual, NULL);
	time_to_end = get_time_in_ms(actual) + time_to_wait;
	while (get_time_in_ms(actual) < time_to_end)
	{
		usleep(100);
		gettimeofday(&actual, NULL);
	}
	return (success);
}
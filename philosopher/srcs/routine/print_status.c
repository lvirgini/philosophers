/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:32:51 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, int status)
{
	static pthread_mutex_t	mutex;
	static struct timeval	begin = {0};
	struct timeval			now;
	static char				*str_status[5] = {
		"has taken a fork",	"is eating", "is sleeping",
		"is thinking", "died",
	};

	if (begin.tv_sec == 0 && begin.tv_usec == 0)
	{
		gettimeofday(&begin, NULL);
		pthread_mutex_init(&mutex, NULL);
	}
	pthread_mutex_lock(&mutex);
	if (philo != NULL && philo->rules->able_to_write == true)
	{
		gettimeofday(&now, NULL);
		printf("%ld ms %d %s\n", get_diff_time_ms(begin, now), philo->id,
			str_status[status]);
	}
	if (status == IS_DEAD)
		philo->rules->able_to_write = false;
	pthread_mutex_unlock(&mutex);
}

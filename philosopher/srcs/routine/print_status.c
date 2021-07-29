/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 13:59:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, int status, t_rules *rules)
{
	struct timeval			now;
	static char				*str_status[5] = {
		"has taken a fork",	"is eating", "is sleeping",
		"is thinking", "died",
	};

	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&now, NULL);
	if (status == IS_DEAD)
	{
		printf("%ld ms %d %s\n", get_diff_time_ms(rules->begin, now), philo->id,
			str_status[status]);
		printf("%ld ms %d %s\n", get_diff_time_ms(rules->begin, now), philo->id,
			str_status[status]);
		printf("PRINT STATUS => %ld now = %ld begin = %ld\n",  
		get_diff_time_ms(philo->last_eat, now), get_time_in_ms(now), get_time_in_ms(rules->begin));
		philo->rules->able_to_write = false;
	}
	else if (philo != NULL && rules->able_to_write == true)
	{
		printf("%ld ms %d %s\n", get_diff_time_ms(rules->begin, now), philo->id,
			str_status[status]);
	}
	pthread_mutex_unlock(&rules->m_print);
}

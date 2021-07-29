/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 16:28:02 by lvirgini         ###   ########.fr       */
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
	if (philo != NULL && rules->able_to_write == true)
	{
		printf("%ld ms %d %s\n", get_diff_time_ms(rules->begin, now), philo->id,
			str_status[status]);
	}
	if (status == IS_DEAD)
		philo->rules->able_to_write = false;
	pthread_mutex_unlock(&rules->m_print);
}

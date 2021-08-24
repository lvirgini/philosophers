/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/24 12:31:18 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	printer_status(t_ms time, int philo_id, int status)
{	
	char			to_print[256];
	int				size_print;
	static int		size_str_status[5] = {18, 11, 13, 13, 6};
	static char		*str_status[5] = {
		" has taken a fork\n",	" is eating\n", " is sleeping\n",
		" is thinking\n", " died\n",
	};

	ft_memset(to_print, '\0', 256);
	size_print = ft_philo_ltoa(time, to_print);
	ft_strncpy(to_print + size_print, " ms ", 4);
	size_print += 4;
	size_print += ft_philo_itoa(philo_id, to_print + size_print);
	ft_strncpy(to_print + size_print, str_status[status],
		size_str_status[status]);
	write (1, to_print, 256);
}

void	print_status(t_philo *philo, int status, t_rules *rules)
{
	/*static char				*str_status[5] = {
		"has taken a fork",	"is eating", "is sleeping",
		"is thinking", "died",
	};*/
	struct timeval			now;

	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&now, NULL);
	if (philo != NULL && rules->able_to_write == true)
	{
		printer_status(get_diff_time_ms(rules->begin, now), philo->id, status);
	//	printf("%ld ms %d %s\n", get_diff_time_ms(rules->begin, now), philo->id,
	//		str_status[status]);
	}
	if (status == IS_DEAD)
		philo->rules->able_to_write = false;
	pthread_mutex_unlock(&rules->m_print);
}

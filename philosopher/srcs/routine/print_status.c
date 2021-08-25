/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:10:15 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/25 15:05:23 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** write exactly the characters necessary to display the status of the
** philosophers.
** optimization compared to printf.
*/

static void	write_status(t_ms time, int philo_id, int status)
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
	write (1, to_print, size_print + size_str_status[status]);
}

/*
** management of status display.
** if the status of a philosophers is "IS_DEAD" it blocks the permission 
** to write to all other philosophers.
*/

void	print_status(t_philo *philo, int status, t_rules *rules)
{
	struct timeval			now;

	pthread_mutex_lock(&rules->m_print);
	gettimeofday(&now, NULL);
	if (philo != NULL && rules->able_to_write == true)
		write_status(get_diff_time_ms(rules->begin, now), philo->id, status);
	if (status == IS_DEAD)
		philo->rules->able_to_write = false;
	pthread_mutex_unlock(&rules->m_print);
}

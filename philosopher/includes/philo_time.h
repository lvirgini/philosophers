/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:43:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/26 14:12:33 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TIME_H
# define PHILO_TIME_H

# include "philosophers.h"

void			ms_sleep(t_ms time_to_wait, t_rules *rules);
void			ft_usleep(suseconds_t time_to_wait);
/*
** time conversion
*/

t_ms			second_to_ms(time_t second);
t_ms			micro_to_ms(suseconds_t micro);

/*
** time utils
*/

t_ms			get_time_in_ms(struct timeval time);
t_ms			get_diff_time_ms(struct timeval begin, struct timeval end);

#endif

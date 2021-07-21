/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_time.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:43:02 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/21 12:42:32 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TIME_H
# define PHILO_TIME_H

# include "philosophers.h"

void			ft_sleep(t_ms time_to_wait);

/*
** time conversion
*/

suseconds_t		ms_to_micro(t_ms ms); //
t_ms			second_to_ms(time_t second);
t_ms			micro_to_ms(suseconds_t micro);

/*
** time utils
*/

t_ms			get_time_in_ms(struct timeval time);
suseconds_t		get_time_in_micro(struct timeval time); //

t_ms			get_diff_time_ms(struct timeval begin, struct timeval end);
suseconds_t		get_diff_time_micro(struct timeval begin, struct timeval end);//

struct timeval	add_timeval(struct timeval t1, struct timeval t2);//

#endif

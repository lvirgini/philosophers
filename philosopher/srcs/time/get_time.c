/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/07 15:57:57 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** return time difference
*/

t_ms	get_diff_time_ms(struct timeval begin, struct timeval end)
{
	return (second_to_ms(end.tv_sec - begin.tv_sec)
			+ micro_to_ms(end.tv_usec - begin.tv_usec));
}

suseconds_t	get_diff_time_micro(struct timeval begin, struct timeval end) //
{
	return (ms_to_micro(second_to_ms(end.tv_sec - begin.tv_sec))
			+ (end.tv_usec - begin.tv_usec));
}

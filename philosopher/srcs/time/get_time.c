/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/31 15:53:05 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** return time difference
*/

t_ms	get_diff_time_ms(struct timeval begin, struct timeval end)
{
	return (get_time_in_ms(end) - get_time_in_ms(begin));
}

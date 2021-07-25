/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/25 11:14:51 by lvirgini         ###   ########.fr       */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_convertor.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 20:26:18 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 10:53:28 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** conversion time
*/

t_ms	micro_to_ms(suseconds_t micro)
{
	return ((t_ms)micro / 1000.0);
}

t_ms	second_to_ms(time_t second)
{
	return ((t_ms)second * 1000);
}

t_ms	get_time_in_ms(struct timeval time)
{
	return (second_to_ms(time.tv_sec) + micro_to_ms(time.tv_usec));
}

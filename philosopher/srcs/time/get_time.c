/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 15:57:31 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 16:25:29 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** return time difference
*/

t_ms	get_diff_time_ms(struct timeval begin, struct timeval end)
{
	return (((end.tv_sec - begin.tv_sec) * 1000)
		+ ((end.tv_usec - begin.tv_usec) / 1000));
}

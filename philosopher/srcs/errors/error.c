/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 11:58:28 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 16:21:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*
** if one philosophers, can't eat because of one fork
** if argv < 4 > 6
*/

int     philo_error(int error, t_dinner_table *table)
{
    if (table)
        free_all_table(table);
    
}
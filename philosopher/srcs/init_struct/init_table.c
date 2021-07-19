/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 15:48:03 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 17:15:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_dinner_table  *init_dinner_table()
{
    t_dinner_table *table;

    table = (t_dinner_table *)malloc(sizeof(t_dinner_table));
    if (table == NULL)
        return (NULL);

}

void        free_table(t_dinner_table *table)
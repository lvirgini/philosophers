/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:41:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/26 14:18:46 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TABLE_H
# define PHILO_TABLE_H

# include "philosophers.h"

typedef struct s_dinner_table
{
	int			nb_philo;
	t_philo		*philos;
	t_fork		*forks;
	t_rules		*rules;
}	t_dinner_table;

int		get_table(char **argv, t_dinner_table *table, t_rules *rules);
void	free_all_table(t_dinner_table *table);

#endif

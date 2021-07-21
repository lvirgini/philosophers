/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 21:41:45 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/21 15:09:41 by lvirgini         ###   ########.fr       */
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
	int			all_alive;
	int			if_all_eat;
}	t_dinner_table;

void	free_all_table(t_dinner_table *table);

#endif

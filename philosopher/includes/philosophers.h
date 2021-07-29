/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:51:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 09:03:41 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

/*
** includes lib extern
*/

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h> //

/*
** includes header from philosophers
*/

# include "philo_utils.h"
# include "philo_rules.h"
# include "philo_fork.h"
# include "philo_time.h"
# include "philo_philo.h"
# include "philo_table.h"

/*
** DINNER_ROOM
**
** philosopher 0 = 1st
** forks 0 = between last and 1st.
**
**  philo n-1	| fork n-1	| philo n	| fork n	| philo n+1	...
**				|			|			|			|
**			 	 (fork_left | philo 0	| fork_right)	
**	philo_last	|fork_right)			( fork left	| philo 1 | fork right)
**
*/

/*
** Errors
*/

enum	e_error
{
	ERR_MALLOC,
	ERR_ARG,
	ERR_THREAD_INIT,
};

int		philo_error(int nb_error, t_dinner_table *table);

/*
** Parsing
*/

int		parse_args(int argc, char **argv, t_dinner_table *table,
			t_rules *rules);

/*
** Start and routines
*/

void	*routine(void *philosopher);
void	eating_routine(t_philo *philo);
void	start_simulation(t_dinner_table *table, t_rules *rules);
void	print_status(t_philo *philo, int status, t_rules *rules);
int		can_write(t_rules *rules);

#endif

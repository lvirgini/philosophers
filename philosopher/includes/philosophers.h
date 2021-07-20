/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:51:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 16:05:30 by lvirgini         ###   ########.fr       */
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

# include "struct_and_utils.h"
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
** fork 0 | philo 0 | fork 1 | philo 1 | ..
*/

/*
** errors
*/

enum	e_error
{
	ERR_MALLOC,
	ERR_ARG,

};

int		parse_args(int argc, char **argv, t_dinner_table *table, t_rules *rules);
int     philo_error(int nb_error, t_dinner_table *table);

#endif

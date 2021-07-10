/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:51:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/08 11:27:15 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> //

enum e_bool
{
	false,
	true,
};

enum	e_success_faillure
{
	success,
	faillure,
};

enum	e_status
{
	IS_THINKING,
	IS_EATING,
	IS_SLEEPING,
};

typedef struct	s_philo t_philo;
typedef struct	s_restaurant t_restaurant;
typedef	long	t_ms;

struct s_philo
{
	t_ms		last_eat;
	int			status;
};

/*
** DINNER_ROOM
**
** philosopher 0 = 1st
** forks 0 = between last and 1st.
**
** fork 0 | philo 0 | fork 1 | philo 1 | ..
*/

struct s_dinner_table			// name ?
{
	int			nb_philo;
	t_philo		**philosophers;
	int			**forks; 		// ?
	t_ms		time_to_eat;
	t_ms		time_to_sleep;
	t_ms		time_to_die;
	int			if_dead;
};


void		ft_sleep(t_ms time_to_wait);

/*
** utils, libft
*/

void		ft_putstr(char *s);
char		*ft_itoa(int n);

/*
** time conversion
*/

suseconds_t	ms_to_micro(t_ms ms);
t_ms		second_to_ms(time_t second);
t_ms		micro_to_ms(suseconds_t micro);

/*
** time utils
*/

t_ms		get_time_in_ms(struct timeval time);
suseconds_t	get_time_in_micro(struct timeval time);

t_ms		get_diff_time_ms(struct timeval begin, struct timeval end);
suseconds_t	get_diff_time_micro(struct timeval begin, struct timeval end);

struct timeval	add_timeval(struct timeval t1, struct timeval t2);
#endif
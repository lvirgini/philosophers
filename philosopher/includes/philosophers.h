/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:51:43 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 17:16:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h> //

/*
** DINNER_ROOM
**
** philosopher 0 = 1st
** forks 0 = between last and 1st.
**
** fork 0 | philo 0 | fork 1 | philo 1 | ..
*/

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

enum	e_fork
{
	IS_FREE,
	IS_TAKEN,
};

typedef struct s_philo t_philo;
typedef struct s_dinner_table t_dinner_table;
typedef struct s_rules t_rules;

typedef	long	t_ms;

struct s_philo
{
	struct timeval	last_eat;
	int				nb_eat;
	int				*fork_right; // adresse identique a philo + 1 fork left
	int				*fork_left;	 // adresse identique a philo - 1 fork right
	int				status;
	pthread_t		thrd_id;
	pthread_mutex_t	m_fork;
	//pthread_mutex_t m_print;
};

struct s_rules
{
	t_ms		time_to_eat;
	t_ms		time_to_sleep;
	t_ms		time_to_die;
	int			nb_meal;
};

struct s_dinner_table
{
	int			nb_philo;
	t_philo		*philosophers;
	int			if_dead;
	int			if_all_eat;
};


void		ft_sleep(t_ms time_to_wait);

/*
** utils, libft
*/

void		ft_putstr(char *s);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);

/*
** time conversion
*/

suseconds_t	ms_to_micro(t_ms ms); //
t_ms		second_to_ms(time_t second);
t_ms		micro_to_ms(suseconds_t micro);

/*
** time utils
*/

t_ms		get_time_in_ms(struct timeval time);
suseconds_t	get_time_in_micro(struct timeval time); //

t_ms		get_diff_time_ms(struct timeval begin, struct timeval end);
suseconds_t	get_diff_time_micro(struct timeval begin, struct timeval end);//

struct timeval	add_timeval(struct timeval t1, struct timeval t2);//

#endif

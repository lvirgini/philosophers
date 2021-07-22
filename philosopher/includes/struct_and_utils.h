/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_and_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:28:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 19:23:45 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_AND_UTILS_H
# define STRUCT_AND_UTILS_H

typedef long	t_ms;

enum e_bool
{
	false,
	true,
};

enum	e_success_faillure
{
	FAILLURE = -1,
	SUCCESS,
};

enum	e_status
{
	TAKEN_FORK,
	IS_EATING,
	IS_SLEEPING,
	IS_THINKING,
	IS_DEAD,
};
/*
** Structure rules
*/

typedef struct s_rules
{
	t_ms			time_to_eat;
	t_ms			time_to_sleep;
	t_ms			time_to_die;
	int				nb_meal;
	struct timeval	begin;
}t_rules;

//t_rules		*init_rules(t_ms tteat, t_ms ttsleep, t_ms ttdie, int nbmeal);
//void		free_rules(t_rules *rules);
//t_rules		*get_rules(int argc, char *argv);

/*
** utils, libft
*/

t_ms		mini_atoi(char *s);
void		ft_putstr(char *s);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_isdigit(int c);
int			ft_isspace(int c);

#endif

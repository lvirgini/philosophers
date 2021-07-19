/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_and_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:28:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 23:28:10 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_AND_UTILS_H
# define STRUCT_AND_UTILS_H

typedef long	t_ms;

typedef struct s_rules
{
	t_ms		time_to_eat;
	t_ms		time_to_sleep;
	t_ms		time_to_die;
	int			nb_meal;
}t_rules;

enum e_bool
{
	false,
	true,
};

enum	e_success_faillure
{
	SUCCESS,
	FAILLURE,
};

enum	e_status
{
	IS_THINKING,
	IS_EATING,
	IS_SLEEPING,
	IS_DEAD,
	TAKEN_FORK,
};

/*
** utils, libft
*/

void		ft_putstr(char *s);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);

#endif

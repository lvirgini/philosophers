/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 22:28:19 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/24 12:18:04 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_UTILS_H
# define PHILO_UTILS_H

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
** utils, libft
*/

t_ms		mini_atoi(char *s);
void		ft_putstr(char *s);
char		*ft_itoa(int n);
void		*ft_memset(void *s, int c, size_t n);
int			ft_isdigit(int c);
int			ft_isspace(int c);

#endif

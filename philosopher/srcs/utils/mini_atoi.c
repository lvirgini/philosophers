/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:20:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/29 16:25:44 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_ms	mini_atoi(char *s)
{
	int				i;
	unsigned long	result;

	if (!s)
		return (-1);
	i = 0;
	result = 0;
	while (s[i] && ft_isdigit(s[i]) && i < 10)
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (s[i] || result > LONG_MAX)
		return (-1);
	return ((t_ms)result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 19:20:20 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/22 19:20:35 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_ms	mini_atoi(char *s)
{
	int		i;
	t_ms	result;

	if (!s)
		return (-1);
	i = 0;
	result = 0;
	while (s[i] && ft_isspace(s[i]))
		i++;
	while (s[i] && ft_isdigit(s[i]))
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}
	if (s[i])
		return (-1);
	return (result);
}

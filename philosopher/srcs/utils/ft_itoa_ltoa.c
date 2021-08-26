/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ltoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 12:28:49 by lvirgini          #+#    #+#             */
/*   Updated: 2021/08/26 14:13:16 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_intlen(unsigned int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n > 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

int	ft_philo_ltoa(long n, char *dst)
{
	int			size;
	int			ret;

	size = ft_intlen(n);
	ret = size;
	if (n == 0)
		dst[0] = '0';
	while (n)
	{
		dst[--size] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

int	ft_philo_itoa(int n, char *dst)
{
	int			size;
	int			ret;

	size = ft_intlen(n);
	ret = size;
	if (n == 0)
		dst[0] = '0';
	while (n)
	{
		dst[--size] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

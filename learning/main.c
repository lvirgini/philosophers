/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:46:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/07 12:17:48 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

void	ft_putstr(char *s)
{
	size_t	i;

	if (s)
	{
		i = 0;
		while (s[i])
			++i;
		write(1, s, i);
	}
}
/*
** Ecrit l'integer (n) sur l'entrée standard.
*/

void	ft_putnbr(int n)
{
        long int        nb;
		size_t			size;

        nb = n;
        if (nb < 0)
        {
                nb = -nb;
                write(1, "-", 1);
        }
        if (nb > 9)
        {
                ft_putnbr(nb / 10);
                ft_putnbr(nb % 10);
        }
        else
        {
                nb += '0';
                write(1, &nb, 1);
        }
}

static size_t   get_integer_size(int n)
{
        unsigned int    unsigned_nbr;
        size_t                  size;

        if (n == 0)
                return (1);
        size = 0;
        if (n < 0)
                size++;
        unsigned_nbr = ft_abs(n);
        while (unsigned_nbr > 0)
        {
                unsigned_nbr /= 10;
                size++;
        }
        return (size);
}

static void     get_str_from_int(char *dst, int n, size_t size)
{
        unsigned int    unsigned_nbr;

        dst[size] = '\0';
        unsigned_nbr = ft_abs(n);
        while (size-- > 0)
        {
                dst[size] = unsigned_nbr % 10 + '0';
                unsigned_nbr /= 10;
        }
        if (n < 0)
                dst[0] = '-';
}

char    *ft_itoa(int n)
{
        size_t          size;
        char            *dst;

        size = get_integer_size(n);
        dst = (char *)malloc(sizeof(char) * (size + 1));
        if (dst == NULL)
                return (NULL);
        get_str_from_int(dst, n, size);
        return (dst);
}

double		micro_to_mili_second(suseconds_t micro)
{
	return (micro / 1000.0);
}

int	main(void)
{
	struct timeval	begin;
	struct timeval	end;
	t_ms	diff_time;

	while (1)
	{
	gettimeofday(&begin, NULL);
	usleep(1000)
	gettimeofday(&end, NULL);
	printf("diff time = %d\n", get_diff)
	}
	ft_putstr(ft_itoa(micro_to_mili_second(end.tv_usec - begin.tv_usec)));
/*	gettimeofday(&end, NULL);
	printf("temps pour faire un for de 0 a 200 : \n%d second; \n%d millisecond\n",
			end.tv_sec - begin.tv_sec, end.tv_usec - begin.tv_usec);
	gettimeofday(&end, NULL);
	ft_putnbr(end.tv_usec - begin.tv_usec);*/

	return (0);
}
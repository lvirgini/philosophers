/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 11:46:53 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/06 12:12:07 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	struct timeval	begin;
	struct timeval	end;

	gettimeofday(&begin, NULL);

	for (int i = 0; i < 20; i++)
		usleep(1);
	gettimeofday(&end, NULL);

	printf("temps pour faire un for de 0 a 200 : \n%d second; \n%d millisecond\n",
			end.tv_sec - begin.tv_sec, end.tv_usec - begin.tv_usec);
	return (0);
}
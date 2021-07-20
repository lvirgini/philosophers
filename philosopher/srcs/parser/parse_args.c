/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:43:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/20 17:41:43 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_rules(t_rules *rules)
{
	if (rules->time_to_eat < 0 || rules->time_to_sleep < 0
			|| rules->time_to_die < 0)
		return (FAILLURE);
	return (SUCCESS);
}

static t_ms	mini_atoi(char *s)
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

static int	get_table(char **argv, t_dinner_table *table)
{
	int    nb_philo;

	nb_philo = (int)mini_atoi(argv[1]);
	if (nb_philo < 1)
		return (FAILLURE);
	table->philos = (t_philo *)malloc(sizeof(t_philo) * nb_philo);
	table->forks = (t_fork *)malloc(sizeof(t_fork) * nb_philo);
	if (!table->forks || !table->philos)
		return (philo_error(ERR_MALLOC, table));
	table->all_alive = true;
	table->if_all_eat = false;
	table->nb_philo = nb_philo;
	return (SUCCESS);
}

static int	get_rules(int argc, char **argv, t_rules *rules)
{
	int		nb_meal;

	nb_meal = -1;
	if (argc == 6)
	{
		nb_meal = (int)mini_atoi(argv[5]);
		if (nb_meal < 1)
			return (FAILLURE);
	}	
	rules->time_to_eat = mini_atoi(argv[2]);
	rules->time_to_sleep = mini_atoi(argv[3]);
	rules->time_to_die = mini_atoi(argv[4]);
	rules->nb_meal = nb_meal;
	return (check_rules(rules));
}

int	parse_args(int argc, char **argv, t_dinner_table *table, t_rules *rules)
{
	if (argc < 4 || argc > 6 || get_rules(argc, argv, rules) == FAILLURE
			|| get_table(argv, table) == FAILLURE)
		return (philo_error(ERR_ARG, NULL));
	return (SUCCESS);
}

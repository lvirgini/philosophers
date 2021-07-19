/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvirgini <lvirgini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 14:43:13 by lvirgini          #+#    #+#             */
/*   Updated: 2021/07/19 15:23:27 by lvirgini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopphers.h"

t_dinner_table  *get_arg(int argc, char **argv)
{
    if (argc < 4 || argc > 6)
        return (str_error(ARG ))

}
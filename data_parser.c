/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:25:19 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 20:25:21 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

int check_args(int args)
{
    if (args == 3)
        return (1);
    if (args < 3)
    {
        printf("Error , You Need More Args\nCheck The Usage ");
        exit(1);
    }
    if (args > 3)
    {
        printf("Error You Pass More Args Than What Expected ...");
        exit (1);
    }
    return (1);
}

int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

int is_a_valid_number(char *data)
{
    while (*data)
    {
        if (!is_digit(*data))
            return (0);
        data++;
    }
    return (1); 
}

int pars_data(int argc, char **argv)
{
    if (!check_args(argc))
    {
        printf("Error On Args ");
        exit (1);
    }
    if (!is_a_valid_number(argv[1]))
    {
        printf("Invalid Process ID , It's Not A Number ...");
        exit (1);
    }
    return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:18:44 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 21:18:45 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

void print_error(char *data)
{
	int	_index;

	_index = 0;
	if (!data)
		return ;
	write(2, "\x1b[31m", 6);
	while (data[_index])
	{
		write(PETT, &data[_index], 1);
		_index++;
	}
	write(PETT, "\n", 1);
	write(2, "\033[0m\n", 4);
}
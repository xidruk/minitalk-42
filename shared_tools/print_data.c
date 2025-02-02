/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:18:21 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 21:18:23 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared_tools.h"

void print_data(char *data)
{
	int	_index;

	_index = 0;
	if (!data)
		return ;
	while (data[_index])
	{
		write(PDTT, &data[_index], 1);
		_index++;
	}
	write(PDTT, "\n", 1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_get_data_size.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:08:25 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 00:08:27 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

int	get_data_size(char *data)
{
	int	len;

	len = 0;
	if (!data)
	{
		print_error("Error <NULL> !\n");
		print_error("Can't get data size !\n");
		exit(1);
	}
	while (data[len])
		len++;
	return (len);
}

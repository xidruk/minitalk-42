/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_marker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:36:44 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 00:36:47 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

int	mark_finale_signal(t_client *client_struct)
{
	if (!client_struct)
	{
		print_error("Error : The given client struct is <NULL>");
		print_error("func-ref:[mark_finale_signal]");
		print_error("f_ref:[client_marker.c]");
		exit(1);
	}
	if (client_struct->s_data_size == client_struct->r_data_size)
	{
		client_struct->final_sgs = 1;
		return (1);
	}
	return (0);
}

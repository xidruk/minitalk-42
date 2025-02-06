/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_cleaner.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:24:32 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 00:24:34 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

void	clean_client_struct(t_client *client_struct)
{
	if (!client_struct)
	{
		print_error("Error <NULL> Client struct !");
		print_error("func-ref:[clean_client_struct]");
		print_error("f-ref:[client_cleaner.c]");
		exit(1);
	}
	client_struct->data_to_send = NULL;
	client_struct->current_state = 0;
	client_struct->final_sgs = 0;
	client_struct->s_data_size = 0;
	client_struct->server_proc_id = 0;
	client_struct->r_data_size = 0;
}

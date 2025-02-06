/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_init_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 00:08:37 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 00:08:39 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

t_client	*gen_client_struct(void)
{
	t_client	*cs;

	cs = malloc(sizeof(t_client));
	if (!cs)
	{
		print_error("Error Malloc Fails <NULL> !");
		print_error("Fails to gen new client struct ...");
		exit(1);
	}
	return (cs);
}

void	init_client_struct(t_client *client_struct, int proc_id, char *data)
{
	if (!client_struct)
	{
		print_error("Error <NULL> Client struct !");
		print_error("func-ref:[init_client_struct]");
		print_error("f-ref:[client_init_s.c]");
		exit(1);
	}
	client_struct->data_to_send = data;
	client_struct->current_state = 0;
	client_struct->final_sgs = 0;
	client_struct->s_data_size = get_data_size(data);
	client_struct->server_proc_id = proc_id;
	client_struct->r_data_size = 0;
}

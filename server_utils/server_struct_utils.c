/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_struct_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 22:44:22 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 22:44:25 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

t_server *gen_server_struct(void)
{
	t_server *ss; // server struct;

	ss = malloc(sizeof(t_server));
	if (!ss)
	{
		print_error("Malloc Fails To Allocate Server Struct ...");
		exit(1);
	}
	return (ss);
}

void init_server_struct(t_server *server_struct)
{
	if (!server_struct)
	{
		print_error("Error The Given Param is Null !");
		exit (1);
	}
	server_struct->received_data = malloc(1024 * sizeof(char));
	if (!server_struct->received_data)
	{
		print_error("Malloc Fails To Allocate Buffer ....");
		exit (1);
	}
	server_struct->current_state = 0;
	server_struct->final_sgs = 0;
	server_struct->r_data_size = 0;
	server_struct->client_proc_id = 0;
	server_struct->death_state = 0;
}

void clean_up_server(t_server *server_struct)
{
	free(server_struct->received_data);
	server_struct->received_data = NULL;
	server_struct->current_state = 0;
	server_struct->final_sgs = 0;
	server_struct->r_data_size = 0;
	server_struct->client_proc_id = 0;
	server_struct->death_state = 0;
}
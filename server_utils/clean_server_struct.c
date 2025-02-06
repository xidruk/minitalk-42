/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_server_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:12:43 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/05 09:12:44 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

void	clean_up_server(t_server *g_server_struct)
{
	if (!g_server_struct)
	{
		print_error("Error : Given Param Is <NULL>");
		print_error("func-ref:[clean_up_server]");
		print_error("f-ref[clean_server_struct.c]");
		exit(1);
	}
	free(g_server_struct->received_data);
	g_server_struct->received_data = NULL;
	g_server_struct->current_state = 0;
	g_server_struct->final_sgs = 0;
	g_server_struct->r_data_size = 0;
	g_server_struct->client_proc_id = 0;
	g_server_struct->death_state = 0;
}

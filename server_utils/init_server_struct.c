/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_server_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 07:52:57 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/05 07:52:59 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

t_server	*gen_server_struct(void)
{
	t_server	*ss;

	ss = malloc(sizeof(t_server));
	if (!ss)
	{
		print_error("Error <NULL> Malloc Fails ...");
		print_error("func-ref:[gen_server_struct]");
		print_error("f-ref[init_server_struct.c]");
		exit(1);
	}
	return (ss);
}

void	init_server_struct(t_server *g_server_struct)
{
	if (!g_server_struct)
	{
		print_error("Error : Given Param Is <NULL>");
		print_error("func-ref:[init_server_struct]");
		print_error("f-ref[init_server_struct.c]");
		exit(1);
	}
	g_server_struct->received_data = malloc((2ULL * 1024 * 1024 * 1024)
			* sizeof(char));
	if (!g_server_struct->received_data)
	{
		print_error("Error <Malloc Fails> ...");
		exit(1);
	}
	g_server_struct->current_state = 0;
	g_server_struct->final_sgs = 0;
	g_server_struct->r_data_size = 0;
	g_server_struct->client_proc_id = 0;
	g_server_struct->death_state = 0;
	g_server_struct->is_client_dead = 0;
}

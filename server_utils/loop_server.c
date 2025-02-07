/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:23:16 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/06 04:23:18 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

void	server_loop(t_server *g_server_struct)
{
	while (!g_server_struct->final_sgs)
	{
		usleep(100000);
		if (g_server_struct->client_proc_id != 0)
		{
			if (kill(g_server_struct->client_proc_id, 0) == -1)
			{
				print_formater("Client Diad Unexpectedly PID $[] ",
					g_server_struct->client_proc_id);
				g_server_struct->is_client_dead = 1;
				g_server_struct->final_sgs = 1;
				break ;
			}
		}
	}
}

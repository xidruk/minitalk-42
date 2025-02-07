/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 04:32:24 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/06 04:32:25 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

void	restart_server_for_next_client(t_server *g_server_struct)
{
	if (g_server_struct->is_client_dead)
	{
		print_error("Client died mid-transmission !");
		print_error("Destroy Server Side !");
		exit(1);
	}
	print_data("Clean Up Server ...");
	clean_up_server(g_server_struct);
	init_server_struct(g_server_struct);
	print_data("Restart Server For New Connection ...");
}

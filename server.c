/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:29:02 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 02:29:03 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

t_server *server_struct = NULL;

int main()
{
	server_struct = gen_server_struct();
	init_server_struct(server_struct);

	printf("Server PID : %d", get_pid());
	while (1)
	{
		server_loop(server_struct);
		if (server_struct->death_state)
			restart_server_for_next_client(server_struct);
	}
	clean_up_server(server_struct);
	free(server_struct);
	return (0);
}
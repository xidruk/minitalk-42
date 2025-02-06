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
	print_data("\nRestarting Server For Next Client !");
	clean_up_server(g_server_struct);
	init_server_struct(g_server_struct);
	print_data("Server Ready For New Conection !");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:28:54 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 02:28:56 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

int main(int argc, char **argv)
{
	if (!pars_data(argc, argv))
	{
		printf("Error");
		exit(1);
	}
	int proc_id = atoi(argv[1]);
	char *data = argv[2];

	t_client *client_struct;
	client_struct = gen_client_struct();
	init_client_struct(client_struct, proc_id, data);
	send_data(client_struct);
	if (mark_file_signal(client_struct))
	{
		send_death_signal(proc_id);
		clean_client_struct(client_struct);
		printf("Data Was Sended Good ... ");
	}
	else 
	{
		printf("Data Was Not Sending Good , Some Error Detected ...");
		exit (1);
	}
	free(client_struct);
	return (0);
}

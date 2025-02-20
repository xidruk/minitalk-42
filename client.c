/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 06:10:45 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/06 06:10:47 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int signal)
{
	if (signal == SIGUSR1)
	{
		g_ack_received = 1;
		print_data("[Client Received Acknowledgement From the Server !]");
	}
}

void	client_start_life(t_client *client_struct, int proc_id, char *data)
{
	init_client_struct(client_struct, proc_id, data);
	print_data("Init The Client Struct ...");
	send_data(client_struct);
	print_data("Send Data To The Server ...");
}

void	kill_client_life_cycle(t_client *client_struct, int proc_id)
{
	print_data("Send Death Signal To The Server ...");
	send_death_signal(proc_id, client_struct);
	clean_client_struct(client_struct);
	print_data("Clean Up The Client Struct ...");
	print_data("Data Was Sent Successfully!");
}

int	main(int argc, char **argv)
{
	int					proc_id;
	struct sigaction	sa;
	t_client			*client_struct;

	signal(SIGINT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	pars_data(argc, argv);
	proc_id = swap_types(argv[1]);
	sa.sa_handler = handle_ack;
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	client_struct = gen_client_struct();
	client_start_life(client_struct, proc_id, argv[2]);
	if (mark_finale_signal(client_struct))
		kill_client_life_cycle(client_struct, proc_id);
	else
	{
		print_data("Data was not sent successfully. An error occurred.");
		free(client_struct);
		exit(1);
	}
	free(client_struct);
	return (0);
}

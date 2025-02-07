/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:22:05 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/06 09:22:07 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "g_header.h"

t_server	*g_server_struct = NULL;

int	main(void)
{
	struct sigaction	sa;

	print_data("Generate the server struct ....");
	g_server_struct = gen_server_struct();
	init_server_struct(g_server_struct);
	print_data("Init the server struct ...");
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	print_formater("Server PID: $[]", getpid());
	while (1)
	{
		server_loop(g_server_struct);
		if (g_server_struct->final_sgs)
			restart_server_for_next_client(g_server_struct);
	}
	clean_up_server(g_server_struct);
	print_data("Clean up the server ...");
	free(g_server_struct);
	return (0);
}

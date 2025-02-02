/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_looper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 04:16:41 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/02 04:16:42 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

void server_loop(t_server *server_struct)
{
    struct  sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

    struct sigaction sa_death;
	sa_death.sa_handler = handle_death_signal;
	sa_death.sa_flags = 0;
	sigaction(SIGUSR1, &sa_death, NULL);

    print_data("Server Is Running ...\n");
    while (!server_struct->final_sgs)
    {
        pause();
    }
    printf("Received data : %s", server_struct->received_data);
}

void restart_server_for_next_client(t_server *server_struct)
{
	printf("Resetting Server for Next Client...\n");
	clean_up_server(server_struct);
	init_server_struct(server_struct);
}
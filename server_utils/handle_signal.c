/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:46:11 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/02 01:46:13 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

void handle_signal(int signal, siginfo_t *info, void *context)
{
	(void)context;
	int bit;

	if (signal == SIGUSR2)
		bit = 1;
	else if (signal == SIGUSR1)
		bit = 0;
	else 
		return ;
	if (server_struct->client_proc_id == 0)
	{
		server_struct->client_proc_id = info->si_pid;
		print_data("New Client Connected ...");
	}
	else if (!check_proces_id(server_struct, info->si_pid))
	{
		print_data("Unexpected Client PID ! ");
		return ;
	}
	process_received_bit(server_struct, bit);
}

void handle_death_signal(int signal)
{
	static int zero_bits_count;

	zero_bits_count = 0;
	if (signal == SIGUSR1)
		zero_bits_count++;
	else
		zero_bits_count = 0;
	if (zero_bits_count == 32)
	{
		print_data("Death Signal Received !");
		server_struct->death_state = 1;
		server_struct->final_sgs = 1;
	}
}
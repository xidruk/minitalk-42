/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_signal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:49:33 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/05 09:49:34 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	int	bit;

	(void)context;
	if (signal == SIGUSR2)
		bit = 1;
	else if (signal == SIGUSR1)
		bit = 0;
	else
		return ;
	if (g_server_struct->client_proc_id != 0
		&& g_server_struct->client_proc_id != info->si_pid)
	{
		print_formater("Ignoring Signal From PID $[]", info->si_pid);
		return ;
	}
	if (g_server_struct->client_proc_id == 0)
	{
		g_server_struct->client_proc_id = info->si_pid;
		print_formater("New Client Connected With PID $[]", info->si_pid);
	}
	process_received_bit(g_server_struct, bit);
	if (kill(info->si_pid, SIGUSR1) == -1)
	{
		print_formater("Server: Failed To Ack PID $[]", info->si_pid);
	}
}

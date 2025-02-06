/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:15:30 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 20:15:33 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

void	send_0bit(int proc_id)
{
	print_data("Client Send Bit : [0]");
	if (kill(proc_id, SIGUSR1) == -1)
	{
		print_error("Kill Func Fails To Send Bit : [0]");
		print_error("func-ref:[send_0bit]");
		print_error("f-ref:[client_send_data.c]");
		exit(1);
	}
}

void	send_1bit(int proc_id)
{
	print_data("Client Send Bit : [1]");
	if (kill(proc_id, SIGUSR2) == -1)
	{
		print_error("Kill Func Fails To Send Bit : [1]");
		print_error("func-ref:[send_1bit]");
		print_error("f-ref:[client_send_data.c]");
		exit(1);
	}
}

void	send_bit(int proc_id, int bit)
{
	int	timeout;

	timeout = 1000;
	if (bit == 0)
		send_0bit(proc_id);
	else
		send_1bit(proc_id);
	while (!g_ack_received && timeout-- > 0)
		usleep(100);
	if (!g_ack_received)
	{
		print_error("Timeout: Client Waiting For Acknowledgment");
		print_error("Error : Not Ack Received ! ");
		print_error("func-ref:[send_bit]");
		print_error("f-ref:[client_send_data.c]");
		exit(1);
	}
	g_ack_received = 0;
}

void	send_data(t_client *client_struct)
{
	unsigned char	tmp;
	int				bit_shifter;

	while (*client_struct->data_to_send)
	{
		tmp = *client_struct->data_to_send;
		bit_shifter = 7;
		while (bit_shifter >= 0)
		{
			send_bit(client_struct->server_proc_id, (tmp >> bit_shifter) & 1);
			bit_shifter--;
		}
		client_struct->r_data_size++;
		client_struct->data_to_send++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_and_s_bytes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:25:00 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/05 09:25:02 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern t_server	*g_server_struct;

void	save_bytes(t_server *g_server_struct, unsigned char byte)
{
	if (g_server_struct->r_data_size >= 2147483648)
	{
		printf("Error: Buffer overflow!");
		printf("You Passed Gib Of Bytes !");
		printf("func-ref:[save_bytes]");
		printf("f-ref:[r_and_s_bytes.c]");
		exit(1);
	}
	g_server_struct->received_data[g_server_struct->r_data_size] = byte;
	g_server_struct->r_data_size++;
	g_server_struct->received_data[g_server_struct->r_data_size] = '\0';
}

void	process_received_bit(t_server *g_server_struct, int bit)
{
	static unsigned char	byte = 0;
	static int				bit_count = 0;

	byte = (byte << 1) | (bit & 1);
	bit_count++;
	if (bit_count == 8)
	{
		if (byte == 0x00)
		{
			print_data("Termination byte received <Closing Connection> !");
			g_server_struct->death_state = 1;
			g_server_struct->final_sgs = 1;
			print_data(g_server_struct->received_data);
		}
		else
		{
			save_bytes(g_server_struct, byte);
		}
		bit_count = 0;
		byte = 0;
	}
}

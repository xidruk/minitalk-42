/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_send_death_signal.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 20:45:46 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/04 20:45:48 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

extern volatile sig_atomic_t	g_ack_received;

void	send_death_signal(int proc_id, t_client *client_struct)
{
	unsigned char	term_byte;
	int				bit_shifter;

	term_byte = 0x00;
	bit_shifter = 7;
	while (bit_shifter >= 0)
	{
		send_bit(proc_id, (term_byte >> bit_shifter) & 1, client_struct);
		bit_shifter--;
	}
}

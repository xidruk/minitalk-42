/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:28:28 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/02 01:28:32 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

void save_bytes(t_server *server_struct, unsigned char byte)
{
    server_struct->received_data[server_struct->r_data_size] = byte;
    server_struct->r_data_size++;
    server_struct->received_data[server_struct->r_data_size] = '\0';
    printf("received byte : %c\n", byte);
}

void process_received_bit(t_server *server_struct, int bit)
{
    static unsigned char byte = 0;
    static int bit_count = 0;

    byte = (byte << 1) | (bit & 1);
    bit_count++;

    if (bit_count == 8)
    {
        save_bytes(server_struct, byte);
        bit_count = 0;
        byte = 0;
    }
}
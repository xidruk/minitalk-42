/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:25:33 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 20:25:35 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_utils_h.h"

void send_bit(int proc_id, int bit)
{
  if (bit == 0)
  {
    if (kill(proc_id, SIGUSR1) == 0)
      printf("Send Bit [0]\n");
    else
    {
      printf("Faisl To Send Bit [0]");
      exit(1);
    }
  }
  else
  {
    if (kill(proc_id, SIGUSR2) == 0)
      printf("Send Bit [1]\n");
    else
    {
      printf("Faisl To Send Bit [1]");
      exit(1);
    }
  }
}

void send_data(t_client *client_struct)
{
  unsigned char tmp;
  int bit_shifter;
  int bit_count;

  while (*client_struct->data_to_send)
  {
    tmp = *client_struct->data_to_send;
    bit_shifter = 7;
    while (bit_shifter >= 0)
    {
      send_bit(client_struct->server_proc_id, (tmp >> bit_shifter) & 1);
      bit_shifter--;
    }
    client_struct->s_data_size++;
    client_struct->data_to_send++;
  }
}

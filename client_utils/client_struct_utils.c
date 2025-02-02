/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_struct_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 20:24:59 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 20:25:01 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_utils_h.h"

int get_data_size(char *data)
{
  int len;

  len = 0;
  if (!data)
  {
    printf("Error the Given Data Is NULL ... ");
    exit (1);
  }
  while (data[len])
    len++;
  return (len);
}

t_client *gen_client_struct(void)
{
  t_client *cs; // client struct

  cs = malloc(sizeof(t_client));
  if (!cs)
  {
    printf("Error To Allocate The Struct ...");
    exit (1);
  }
  return (cs);
}

void init_client_struct(t_client *client_struct, int proc_id, char *data)
{
  if (!client_struct)
  {
    printf("The Given Client Struct Is NULL ...");
    exit (1);
  }
  client_struct->data_to_send = data;
  client_struct->current_state = 0;
  client_struct->final_sgs = 0;
  client_struct->s_data_size = get_data_size(data);
  client_struct->server_proc_id = proc_id;
  client_struct->r_data_size = 0;
}

void clean_client_struct(t_client *client_struct)
{
  if(!clean_client_struct)
  {
    printf("Struct Null");
    exit (1);
  }
  client_struct->data_to_send = NULL;
  client_struct->current_state = 0;
  client_struct->final_sgs = 0;
  client_struct->s_data_size = 0;
  client_struct->server_proc_id = 0;
  client_struct->r_data_size = 0;
}

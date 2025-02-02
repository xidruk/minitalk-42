/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_header.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:10:07 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 02:10:09 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef G_HEADER_H
# define G_HEADER_H

//===> include libraries

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <sys/types.h>
# include "client_utils/client_utils_h.h"
# include "server_utils/server_utils_h.h"
# include "shared_tools/shared_tools.h"

//===> define macros

# define DEATH_STATE 0

//===> Type def 

typedef struct client_s {
  char *data_to_send;
  int current_state;
  int final_sgs;
  int s_data_size;
  int r_data_size;
  int server_proc_id;
} t_client;

typedef struct server_s {
  char *received_data;
  int current_state;
  int final_sgs;
  int r_data_size;
  int client_proc_id;
  int death_state;
} t_server;


//===> Extern Variables

extern t_server *server_struct;

#endif

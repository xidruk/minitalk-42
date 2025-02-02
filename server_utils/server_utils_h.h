/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils_h.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:26:21 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 02:26:23 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_UTILS_H
# define SERVER_UTILS_H

//===> Include Libraries 

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <sys/types.h>
# include "../g_header.h"
# include "../shared_tools/shared_tools.h"



//===> Functions 
t_server *gen_server_struct(void);
void init_server_struct(t_server *server_struct);
void clean_up_server(t_server *server_struct);
int mark_final_signal(t_server *server_struct);
int	check_proces_id(t_server *server_struc, int new_proc_id);
void process_received_bit(t_server *server_struct, int bit);
void save_bytes(t_server *server_struct, unsigned char byte);
void handle_signal(int signal, siginfo_t *info, void *context);
void handle_death_signal(int signal);
void server_loop(t_server *server_struct);
void restart_server_for_next_client(t_server *server_struct);

#endif

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

//===> data parsing functions  


//===> Client Functions 

void send_bit(int proc_id, int bit);
void send_data(t_client *client_struct);
t_client *gen_client_struct(void);
void init_client_struct(t_client *client_struct, int proc_id, char *data);
int get_data_size(char *data);
int pars_data(int argc, char **argv);
void clean_client_struct(t_client *client_struct);
void    send_death_signal(int proc_id);
int	mark_file_signal(t_client *client_struct);

//===> Server Functions 

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


//===> Shared Utils 

//===> Define Macros
// PETT ?= Print Error To TTY
// PDTT ?= Print Data To TTY

# define PETT 2
# define PDTT 1

//===> Functions 
void print_error(char *data);
void print_data(char *data);

#endif

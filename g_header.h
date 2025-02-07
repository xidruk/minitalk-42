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
# include <errno.h>

//===> define macros
// PETT ?= Print Error To TTY
// PDTT ?= Print Data To TTY

# define PETT 2
# define PDTT 1

//===> Type def Structs

typedef struct client_s {
	char				*data_to_send;
	int					current_state;
	int					final_sgs;
	unsigned long long	s_data_size;
	unsigned long long	r_data_size;
	int					server_proc_id;
}	t_client;

typedef struct server_s {
	char				*received_data;
	int					current_state;
	int					final_sgs;
	unsigned long long	r_data_size;
	int					client_proc_id;
	int					death_state;
	int					is_client_dead;
}	t_server;

//===> Client Functions

void		clean_client_struct(t_client *client_struct);
int			get_data_size(char *data);
t_client	*gen_client_struct(void);
void		init_client_struct(t_client *client_struct,
				int proc_id, char *data);
int			mark_finale_signal(t_client *client_struct);
void		send_0bit(int proc_id);
void		send_1bit(int proc_id);
void		send_bit(int proc_id, int bit);
void		send_data(t_client *client_struct);
void		send_death_signal(int proc_id);

//===> Extern Structs

extern t_server					*g_server_struct;
extern volatile sig_atomic_t	g_ack_received;

//===> Server Functions
void		clean_up_server(t_server *g_server_struct);
void		handle_signal(int signal, siginfo_t *info, void *context);
t_server	*gen_server_struct(void);
void		init_server_struct(t_server *g_server_struct);
void		server_loop(t_server *g_server_struct);
void		save_bytes(t_server *g_server_struct, unsigned char byte);
void		process_received_bit(t_server *g_server_struct, int bit);
void		restart_server_for_next_client(t_server *g_server_struct);

// ===> Shared Utils Functions !
int			check_args(int args);
int			is_digit(char c);
int			is_a_valid_number(char *data);
int			pars_data(int argc, char **argv);
void		print_data(char *data);
void		print_error(char *data);
int			get_nlen(int num);
void		process_negative_number(int num, char *buffer);
void		process_positive_number(int num, char *buffer);
void		print_integer(int num);
void		print_formater(char *buffer, int number);
int			swap_types(char *str);

#endif

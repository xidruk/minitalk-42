/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils_h.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 02:26:03 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 02:26:05 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_UTILS_H
# define CLIENT_UTILS_H


# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

#include "../g_header.h"
#include "../shared_tools/shared_tools.h"

void send_bit(int proc_id, int bit);
void send_data(t_client *client_struct);
t_client *gen_client_struct(void);
void init_client_struct(t_client *client_struct, int proc_id, char *data);
int get_data_size(char *data);
int pars_data(int argc, char **argv);
void clean_client_struct(t_client *client_struct);
void    send_death_signal(int proc_id);
int	mark_file_signal(t_client *client_struct);

#endif

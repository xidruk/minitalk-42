/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_struct_controller.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:44:45 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 19:44:46 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_utils_h.h"

int	mark_file_signal(t_client *client_struct)
{
	if (!client_struct)
	{
		printf("Null Parameter ...");
		exit (1);
	}
	if (client_struct->s_data_size == client_struct->r_data_size)
	{
		client_struct->final_sgs = 1;
		return (1);
	}
	return (0);
}
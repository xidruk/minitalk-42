/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 01:06:42 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/02 01:06:44 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

int	check_proces_id(t_server *server_struc, int new_proc_id)
{
	if (server_struc->client_proc_id == new_proc_id)
		return (1);
	return (0);
}
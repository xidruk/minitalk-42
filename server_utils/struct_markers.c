/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_markers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 23:10:15 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 23:10:17 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_utils_h.h"

int mark_final_signal(t_server *server_struct)
{
    if (server_struct->death_state == 1)
    {
        server_struct->final_sgs = 1;
        return (1);
    }
    return (0);
}

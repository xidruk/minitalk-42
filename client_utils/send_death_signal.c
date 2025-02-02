/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_death_signal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 19:33:22 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 19:33:24 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client_utils_h.h"

void	send_death_signal(int proc_id)
{
	int	count;

	count = 0;
	while (count < 32)
	{
		send_bit(proc_id, DEATH_STATE);
		count++;
	}
}

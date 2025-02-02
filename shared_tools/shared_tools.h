/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_tools.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 21:11:41 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/01 21:11:42 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_TOOLS_H
# define SHARED_TOOLS_H

//===> Include Libraries 
# include <unistd.h>

//===> Define Macros
// PETT ?= Print Error To TTY
// PDTT ?= Print Data To TTY

# define PETT 2
# define PDTT 1

//===> Functions 
void print_error(char *data);
void print_data(char *data);

#endif

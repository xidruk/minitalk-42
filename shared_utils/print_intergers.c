/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_intergers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarkan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 22:51:23 by kbarkan           #+#    #+#             */
/*   Updated: 2025/02/05 22:51:24 by kbarkan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../g_header.h"

int	get_nlen(int num)
{
	int	len;
	int	sign;

	len = 0;
	sign = 1;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		sign = -1;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	if (sign < 0)
		return (len + 1);
	return (len);
}

void	process_negative_number(int num, char *buffer)
{
	int	_index;

	_index = get_nlen(num);
	buffer[0] = '-';
	num = -num;
	buffer[_index] = '\0';
	_index--;
	while (num > 0)
	{
		buffer[_index--] = (num % 10) + '0';
		num /= 10;
	}
	_index = 0;
	while (buffer[_index])
	{
		write(1, &buffer[_index], 1);
		_index++;
	}
}

void	process_positive_number(int num, char *buffer)
{
	int	_index;

	_index = get_nlen(num);
	buffer[_index] = '\0';
	_index--;
	while (num > 0)
	{
		buffer[_index--] = (num % 10) + '0';
		num /= 10;
	}
	_index = 0;
	while (buffer[_index])
	{
		write(1, &buffer[_index], 1);
		_index++;
	}
}

void	print_integer(int num)
{
	int		size;
	char	*tmp;

	size = get_nlen(num);
	if (num == 0)
	{
		write(1, "0", 1);
		return ;
	}
	tmp = malloc ((size + 1) * sizeof(char));
	if (num < 0)
	{
		process_negative_number(num, tmp);
		free(tmp);
		return ;
	}
	else
	{
		process_positive_number(num, tmp);
		free(tmp);
		return ;
	}
}

void	print_formater(char *buffer, int number)
{
	int	_index;

	_index = 0;
	while (buffer[_index])
	{
		if (buffer[_index] == '$')
		{
			write(1, "$", 1);
			write(1, "[", 1);
			print_integer(number);
			write(1, "]", 1);
			break ;
		}
		else
			write(1, &buffer[_index], 1);
		_index++;
	}
	write(1, "\n", 1);
}

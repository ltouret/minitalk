/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:23:49 by ltouret           #+#    #+#             */
/*   Updated: 2021/08/31 19:24:04 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

t_server	*get_data(void)
{
	static t_server	data;

	return (&data);
}

void	print_char(void)
{
	t_server	*data;

	data = get_data();
	if (data->bit == 8)
	{
		write(1, &data->c, 1);
		data->c = 0;
		data->bit = 0;
	}
}

void	sig_one(void)
{
	t_server	*data;

	data = get_data();
	data->c |= 1 << data->bit;
	data->bit++;
	print_char();
}

void	sig_two(void)
{
	t_server	*data;

	data = get_data();
	data->bit++;
	print_char();
}

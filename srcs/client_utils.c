/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 19:16:14 by ltouret           #+#    #+#             */
/*   Updated: 2021/09/02 13:58:04 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	*get_received(void)
{
	static int	i = 0;

	return (&i);
}

void	panic(t_error err)
{
	if (err == ERR_ARGS_NUM)
		ft_putstr_fd("Error:\nArguments must be PID then string\n", 2);
	if (err == ERR_PID)
		ft_putstr_fd("Error:\nIncorrect PID format\n", 2);
	if (err == ERR_ARGS_STR)
		ft_putstr_fd("Error:\nSending empty string\n", 2);
	if (err == ERR_SERVER)
		ft_putstr_fd("Error:\nServer not online\n", 2);
	exit(err);
}

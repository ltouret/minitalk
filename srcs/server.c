/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:00:03 by ltouret           #+#    #+#             */
/*   Updated: 2021/08/31 19:55:55 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	t_server	*data;

	(void)ucontext;
	data = get_data();
	if (data->s_pid != info->si_pid)
	{
		data->c = 0;
		data->bit = 0;
	}
	data->s_pid = (info->si_pid);
	data->received = 1;
	if (sig == SIGUSR1)
		sig_one();
	else
		sig_two();
}

static void	sig_init(void)
{
	sigset_t			sig_mask;
	struct sigaction	sig1;
	struct sigaction	sig2;

	sigemptyset(&sig_mask);
	sigaddset(&sig_mask, SIGUSR1);
	sigaddset(&sig_mask, SIGUSR2);
	sig1.sa_mask = sig_mask;
	sig2.sa_mask = sig_mask;
	sig1.sa_flags = SA_SIGINFO;
	sig2.sa_flags = SA_SIGINFO;
	sig1.sa_sigaction = sig_handler;
	sig2.sa_sigaction = sig_handler;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
}

static void	server_init(void)
{
	t_server	*data;

	data = get_data();
	data->c = 0;
	data->bit = 0;
	data->s_pid = 0;
	data->received = 0;
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
}

int	main(void)
{
	t_server	*data;

	server_init();
	sig_init();
	data = get_data();
	while (1)
	{
		while (!data->received)
			usleep(1000);
		data->received = 0;
		kill(data->s_pid, SIGUSR1);
	}
	return (0);
}

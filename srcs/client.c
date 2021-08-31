/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:00:19 by ltouret           #+#    #+#             */
/*   Updated: 2021/08/31 19:56:13 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

static void	sig_handler(int n)
{
	(void)n;
	*get_received() = 1;
}

static void	send_bit(char **argv, int i, int bit)
{
	if ((argv[2][i] >> bit) & 1)
		kill(ft_atoi(argv[1]), SIGUSR1);
	else
		kill(ft_atoi(argv[1]), SIGUSR2);
	while (!(*get_received()))
	{
		usleep(1000);
		if (kill(ft_atoi(argv[1]), 0) != 0)
			panic(ERR_SERVER);
	}
	*get_received() = 0;
}

static void	sig_init(void)
{
	struct sigaction	sig1;
	sigset_t			sig_mask;

	sigemptyset(&sig_mask);
	sigaddset(&sig_mask, SIGUSR1);
	sig1.sa_mask = sig_mask;
	sig1.sa_flags = SA_SIGINFO;
	sig1.sa_handler = sig_handler;
	sigaction(SIGUSR1, &sig1, NULL);
}

static void	args_check(int argc, char *argv[])
{
	if (argc != 3)
		panic(ERR_ARGS_NUM);
	if (ft_atoi(argv[1]) <= 0)
		panic(ERR_PID);
	if (kill(ft_atoi(argv[1]), 0) != 0)
		panic(ERR_SERVER);
}

int	main(int argc, char *argv[])
{
	int		i;
	int		bit;

	args_check(argc, argv);
	sig_init();
	i = 0;
	while (argv[2][i])
	{
		bit = 0;
		while (bit < 8)
		{
			send_bit(argv, i, bit);
			bit++;
		}
		i++;
	}
	if (argv[2][0] != '\0')
		ft_putstr_fd("Data sent...\n", 1);
	else
		ft_putstr_fd("Nothing to send...\n", 1);
	return (0);
}

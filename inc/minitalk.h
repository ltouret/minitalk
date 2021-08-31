/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltouret <ltouret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 01:24:19 by ltouret           #+#    #+#             */
/*   Updated: 2021/08/31 20:43:53 by ltouret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define	MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>

typedef struct s_server
{
	pid_t		s_pid;
	char		c;
	int			bit;
	int			received;
}				t_server;

typedef enum e_error
{
	ERR_ARGS_NUM,
	ERR_PID,
	ERR_SERVER
}				t_error;

void			panic(t_error err);
int				*get_received(void);
t_server		*get_data(void);
void			print_char(void);
void			sig_one(void);
void			sig_two(void);
int				ft_atoi(const char *str);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:08:10 by iabasala          #+#    #+#             */
/*   Updated: 2025/01/18 19:56:43 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bittoascii(int signal, siginfo_t *info, void *context)
{
	static int		bit = 0;
	static int		char_inbinary = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		bit = 0;
		char_inbinary = 0;
	}
	if (signal == SIGUSR1)
		char_inbinary |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &char_inbinary, 1);
		bit = 0;
		char_inbinary = 0;
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sasa;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("❌error: you must have only one argument argv[0]");
		return (1);
	}
	pid = getpid();
	ft_printf("server's PID is : %d\n", pid);
	sasa.sa_sigaction = ft_bittoascii;
	sasa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sasa, NULL);
	sigaction(SIGUSR2, &sasa, NULL);
	while (1)
	{
		pause();
	}
}

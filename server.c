/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 17:08:10 by iabasala          #+#    #+#             */
/*   Updated: 2025/01/11 17:08:10 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void ft_bitToAscii(int signal,siginfo_t *info,void *context)
{
    static int bit = 0;
    static int charInBinary = 0;
    static pid_t client_pid = 0;
    (void)context;
    if(client_pid == 0)
        client_pid = info->si_pid;
    if(client_pid != info->si_pid)
    {
        client_pid = info->si_pid;
        bit = 0;
        charInBinary = 0;
    }
    if(signal == SIGUSR1)
      charInBinary |= (1 << (7 - bit));
    bit++;
    if(bit == 8)
    {
        write(1,&charInBinary,1);
        bit = 0;
        charInBinary = 0;
    }
}

int main(int argc, char **argv)
{

    (void)argv;
    if(argc != 1)
    {
        ft_printf("❌error: you must have only one argument argv[0]");
        return 1;
    }
    int pid = getpid();
    ft_printf("server's PID is : %d\n", pid);
    struct sigaction sasa;
    sasa.sa_sigaction = ft_bitToAscii;
    sasa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1,&sasa,NULL);
    sigaction(SIGUSR2,&sasa,NULL);

    while(1)
    {
        pause();
    }
}
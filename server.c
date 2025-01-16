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

void ft_bitToAscii(int signal)
{
    static int bit = 0;
    static int charInBinary = 0;
    if(signal == SIGUSR1)
    // charInBinary |= (1 << bit);
        charInBinary |= (1 << (7 - bit));
    bit++;
    if(bit == 7)
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
        printf("error: you must have only one argument argv[0]");
        return 1;
    }
    int pid = getpid();
    printf("server's PID is : %d\n", pid);
    signal(SIGUSR1, ft_bitToAscii);
    signal(SIGUSR2, ft_bitToAscii);
    while(1)
    {
        pause();
    }
}
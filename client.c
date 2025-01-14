/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iabasala <iabasala@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 13:51:26 by iabasala          #+#    #+#             */
/*   Updated: 2025/01/11 13:51:26 by iabasala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
size_t ft_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}

int	ft_atoi(const char *str)
{
	int	i;
	int	num;
	int	sign;

	i = 0;
	num = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13)||str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (sign * num);
}
void send_caracter(int pid, char c)
{
    int bit = 7;
    while(bit>=0)
    {
        if((c >> bit) & 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);
        usleep(500);
        bit--;
    }
}
int main(int argc, char **argv)
{
    if(argc != 3)
    {       
         write(2,"must be like this: ./client [PID] [message]\n",43);
        return (1);
    }
    int server_pid = ft_atoi(argv[1]);
    if(server_pid <= 0)
        {     
            write(2,"server's pid is invalid\n",24);
            return (1);
        } 
    int i = 0;
    char *message = argv[2];
    while(i<ft_strlen(message))
    {
        send_caracter(server_pid,message[i]);
        i++;
    }
    send_caracter(server_pid,'\0');
    return 0;
}
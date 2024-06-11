/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngoyat <ngoyat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 19:18:40 by ngoyat            #+#    #+#             */
/*   Updated: 2024/06/06 17:55:30 by ngoyat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

// converting binary signals received via "SIGUSR1" and "SIGUSR2" -
// signals into ASCII characters.
// sig represents signal received
// bit keeps track of current position within a BYTE 
// i represents the byte being constructed
void	ft_btoa(int sig)
{
	static int	bit;
	static int	i;
	static int	index;
	static char	message[BUFFER_SIZE];

	if (sig == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		message[index] = i;
		index++;
		if (i == '\0' || index >= BUFFER_SIZE - 1)
		{
			message[index] = '\0';
			ft_printf("Received message: %s\n", message);
			index = 0;
		}
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error\n");
		return (1);
	}
	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, ft_btoa);
		signal(SIGUSR2, ft_btoa);
		pause();
	}
	return (0);
}

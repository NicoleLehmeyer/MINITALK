/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:48:50 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/11/09 13:48:52 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_store = 0;

void	print_char(int sig)
{
	static int	bit;
	static int	i;

	if (sig == SIGUSR1)
		i = ((1 << bit) | i);
	bit++;
	if (bit == 8)
	{
		g_store = i;
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_handler = print_char;
	sa.sa_flags = 0;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Sigaction\n");
		return (1);
	}
	ft_printf("Input in client terminal with prototype");
	ft_printf(" \"./client *PID* *MESSAGE_AS_ARGUMENT*\"");
	ft_printf("\nPID: %d\n", getpid());
	while (1)
	{
		if (g_store != 0)
		{
			ft_printf("%c", g_store);
			g_store = 0;
			sleep(1);
		}
	}
	return (0);
}

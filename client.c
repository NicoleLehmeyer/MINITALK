/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlehmeye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:48:41 by nlehmeye          #+#    #+#             */
/*   Updated: 2023/11/09 13:48:43 by nlehmeye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_atob(int pid, char c)
{
	int	bit_count;

	bit_count = 0;
	while (bit_count != 8)
	{
		if ((c >> bit_count) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit_count++;
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			ft_atob((ft_atoi(argv[1])), (argv[2][i]));
			i++;
		}
		ft_atob(ft_atoi(argv[1]), '\n');
	}
	else
	{
		ft_printf("Error: Check arguments\n");
		return (1);
	}
	return (0);
}

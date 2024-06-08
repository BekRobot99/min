/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_client_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:20:55 by abekri            #+#    #+#             */
/*   Updated: 2024/05/29 17:22:37 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	mult;
	int	nb;

	mult = 1;
	nb = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		i++;
	}
	nb *= mult;
	return (nb);
}

void	check_argument_count(int argc, char *argv[])
{
	const char	*usage_message = "Usage: %s [pid] [message]\n";

	if (argc != 3)
	{
		ft_printf(usage_message, argv[0]);
		exit(EXIT_FAILURE);
	}
}

int	get_pid(char *pid_arg)
{
	int	pid;

	pid = ft_atoi(pid_arg);
	if (pid <= 0)
	{
		ft_printf("Invalid PID: %s\n", pid_arg);
		exit(EXIT_FAILURE);
	}
	return (pid);
}

void	send_message(char *message, int pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		if (char_to_bin(message[i], pid) == -1)
		{
			ft_printf("Sending character failed: %c\n", message[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	if (char_to_bin('\0', pid) == -1)
	{
		ft_printf("Sending null character failed\n");
		exit(EXIT_FAILURE);
	}
}

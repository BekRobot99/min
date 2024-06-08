/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 15:41:24 by abekri            #+#    #+#             */
/*   Updated: 2024/05/29 19:15:44 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf2/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static volatile sig_atomic_t	g_receiver = 0;

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	(void)signum;
	(void)info;
	(void)context;
	g_receiver = 1;
}

void	set_signal_handlers(struct sigaction *sa)
{
	ft_memset(sa, 0, sizeof(*sa));
	sa->sa_sigaction = &sig_handler;
	sigemptyset(&sa->sa_mask);
	sa->sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, sa, NULL) == -1)
	{
		ft_printf("sigaction(SIGUSR1)");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, sa, NULL) == -1)
	{
		ft_printf("sigaction(SIGUSR2)");
		exit(EXIT_FAILURE);
	}
}

int	char_to_bin(char c, int pid)
{
	int	bit_index;
	int	i;

	bit_index = 7;
	i = 0;
	while (bit_index >= 0)
	{
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_receiver)
		{
			if (i == 50)
			{
				return (0);
			}
			usleep(100);
			i++;
		}
		g_receiver = 0;
		bit_index--;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	struct sigaction	sa;
	int					pid;

	check_argument_count(argc, argv);
	pid = get_pid(argv[1]);
	set_signal_handlers(&sa);
	send_message(argv[2], pid);
	return (0);
}

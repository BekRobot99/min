/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:26:40 by abekri            #+#    #+#             */
/*   Updated: 2024/05/29 19:17:54 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_printf2/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define INITIAL_BUFFER_SIZE 1024

void	handle_end_of_message(t_handler_context_t *ctx)
{
	ctx->message[ctx->msg_index] = '\0';
	write(STDOUT_FILENO, ctx->message, ctx->msg_index);
	write(STDOUT_FILENO, "\n", 1);
	free(ctx->message);
	ctx->message = NULL;
	ctx->msg_index = 0;
	ctx->buffer_size = INITIAL_BUFFER_SIZE;
	kill(ctx->pid, SIGUSR1);
}

void	initialize_static_variables(t_handler_context_t *ctx)
{
	if (ctx->message == NULL)
	{
		ctx->message = init_message_buffer(ctx->buffer_size);
		ctx->msg_index = 0;
		ctx->i = 0;
		ctx->c = 0;
	}
}

void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static t_handler_context_t	ctx = {0, 0, 0, NULL, 0, INITIAL_BUFFER_SIZE};

	(void)context;
	ctx.pid = info->si_pid;
	initialize_static_variables(&ctx);
	bin_to_char(signum, &ctx.c);
	if (++ctx.i == 8)
	{
		ctx.i = 0;
		process_received_char(&ctx);
		ctx.c = 0;
	}
	kill(ctx.pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler");
		exit(EXIT_FAILURE);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (EXIT_SUCCESS);
}

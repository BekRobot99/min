/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_server_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:31:57 by abekri            #+#    #+#             */
/*   Updated: 2024/05/29 17:58:22 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	bin_to_char(int signum, char *c)
{
	if (signum == SIGUSR1)
		*c = (*c << 1) | 1;
	else if (signum == SIGUSR2)
		*c <<= 1;
}

char	*init_message_buffer(int buffer_size)
{
	char	*message;

	message = (char *)malloc(buffer_size * sizeof(char));
	if (!message)
	{
		ft_printf("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}
	return (message);
}

void	reallocate_message_buffer(t_handler_context_t *ctx)
{
	char	*new_message;
	int		j;

	new_message = (char *)malloc(ctx->buffer_size * 2 * sizeof(char));
	if (!new_message)
	{
		ft_printf("Failed to allocate memory");
		free(ctx->message);
		exit(EXIT_FAILURE);
	}
	j = 0;
	while (j < ctx->buffer_size)
	{
		new_message[j] = ctx->message[j];
		j++;
	}
	free(ctx->message);
	ctx->message = new_message;
	ctx->buffer_size *= 2;
}

void	process_received_char(t_handler_context_t *ctx)
{
	if (ctx->c == '\0')
	{
		handle_end_of_message(ctx);
	}
	else
	{
		if (ctx->msg_index >= ctx->buffer_size - 1)
		{
			reallocate_message_buffer(ctx);
		}
		ctx->message[ctx->msg_index++] = ctx->c;
	}
}

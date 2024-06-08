/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 17:33:35 by abekri            #+#    #+#             */
/*   Updated: 2024/05/29 17:33:35 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <signal.h>
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define STDERR stderr
# define EXIT_FAILURE 0

typedef struct t_handler
{
	int		pid;
	int		i;
	char	c;
	char	*message;
	int		msg_index;
	int		buffer_size;
}	t_handler_context_t;

int		ft_atoi(const char *str);
int		ft_printf(const char *format, ...);
int		ft_put_in_format(char conv, va_list ap);
int		ft_nbrlen(int n);
void	ft_putptr(void *ptr);
int		ft_ptrlen(void *ptr);
void	ft_putnbr_base(unsigned int nbr, char *base);
void	ft_put_unbr_fd(unsigned int n, int fd);
void	ft_putull_base(unsigned long long nbr, char *base);
int		ft_nbrlen_base(unsigned long long n, int base);

int		ft_put_s(char *ap);
int		ft_put_d(signed int ap);
int		ft_put_c(char ap);
int		ft_put_p(void *ap);
int		ft_put_x(unsigned int ap);
int		ft_put_hexa(unsigned int ap);
int		ft_put_i(int ap);
int		ft_put_u(unsigned int ap);
int		ft_unbrlen(unsigned int n);
void	ft_putchar_fd1(char c, int fd);
void	ft_putnbr_fd1(int n, int fd);
void	ft_putstr_fd1(char *s, int fd);
char	*ft_strchr1(const char *str, int c);
size_t	ft_strlen2(const char *s);
void	*ft_memset(void *str, int c, size_t n);
int		char_to_bin(char c, int pid);
void	bin_to_char(int signum, char *c);
void	check_argument_count(int argc, char *argv[]);
int		get_pid(char *pid_arg);
void	set_signal_handlers(struct sigaction *sa);
void	send_message(char *message, int pid);
char	*init_message_buffer(int buffer_size);
void	reallocate_message_buffer(t_handler_context_t *ctx);
void	process_received_char(t_handler_context_t *ctx);
void	handle_end_of_message(t_handler_context_t *ctx);
void	initialize_static_variables(t_handler_context_t *ctx);

#endif

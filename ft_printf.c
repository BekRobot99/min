/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 01:20:05 by abekri            #+#    #+#             */
/*   Updated: 2024/04/02 06:52:57 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_in_format(char conv, va_list ap)
{
	if (conv == 'c')
		return (ft_put_c((char)va_arg(ap, int)));
	else if (conv == 's')
		return (ft_put_s(va_arg(ap, char *)));
	else if (conv == 'p')
		return (ft_put_p(va_arg(ap, void *)));
	else if (conv == 'd')
		return (ft_put_d(va_arg(ap, signed int)));
	else if (conv == 'i')
		return (ft_put_i(va_arg(ap, int)));
	else if (conv == 'u')
		return (ft_put_u(va_arg(ap, unsigned int)));
	else if (conv == 'x')
		return (ft_put_x(va_arg(ap, unsigned long int)));
	else if (conv == 'X')
		return (ft_put_hexa(va_arg(ap, unsigned long int)));
	else if (conv == '%')
		return (ft_put_c('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	char const	*convs;
	int			count;

	count = 0;
	convs = "cspdiuxX%";
	va_start(ap, format);
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar_fd1(*format, 1);
			count++;
		}
		if (*format++ == '%')
		{
			if (ft_strchr1(convs, *format) && *format)
			{
				count += ft_put_in_format(*format, ap);
			}
			format++;
		}
	}
	va_end(ap);
	return (count);
}

// int	main(void)
// {
// 	int	x;
// 	int	y;

// 	x = ft_printf("%x", 16);
// 	y = ft_printf("%s", NULL);
// 	ft_printf("Hello 42");
// 	return (0);
// }

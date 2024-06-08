/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:42:20 by abekri            #+#    #+#             */
/*   Updated: 2024/04/01 07:53:18 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_fd1(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd1(int n, int fd)
{
	if (n == -2147483648)
	{
		ft_putstr_fd1("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar_fd1('-', fd);
	}
	if (n < 10)
	{
		ft_putchar_fd1(n + '0', fd);
		return ;
	}
	ft_putnbr_fd1(n / 10, fd);
	ft_putchar_fd1((n % 10) + '0', fd);
	return ;
}

void	ft_putstr_fd1(char *s, int fd)
{
	if (!s)
		return ;
	while (*s)
	{
		ft_putchar_fd1(*s++, fd);
	}
}

char	*ft_strchr1(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char) c)
			return ((char *) str);
		str++;
	}
	if (*str == (char) c)
	{
		return ((char *) str);
	}
	return (NULL);
}

void	ft_put_unbr_fd(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd1(n + '0', fd);
		return ;
	}
	ft_putnbr_fd1(n / 10, fd);
	ft_putchar_fd1((n % 10) + '0', fd);
	return ;
}

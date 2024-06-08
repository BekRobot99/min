/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 07:40:52 by abekri            #+#    #+#             */
/*   Updated: 2024/04/02 02:18:36 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_c(char ap)
{
	ft_putchar_fd1(ap, 1);
	return (1);
}

int	ft_put_d(signed int ap)
{
	ft_putnbr_fd1(ap, 1);
	return (ft_nbrlen(ap));
}

int	ft_put_i(int ap)
{
	ft_putnbr_fd1(ap, 1);
	return (ft_nbrlen(ap));
}

int	ft_put_s(char *ap)
{
	if (!ap)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd1(ap, 1);
	return (ft_strlen2(ap));
}

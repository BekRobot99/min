/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:28:13 by abekri            #+#    #+#             */
/*   Updated: 2024/04/03 02:28:13 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hexa(unsigned int ap)
{
	ft_putnbr_base(ap, "0123456789ABCDEF");
	return (ft_nbrlen_base(ap, 16));
}

int	ft_put_x(unsigned int ap)
{
	ft_putnbr_base(ap, "0123456789abcdef");
	return (ft_nbrlen_base(ap, 16));
}

int	ft_put_p(void *ap)
{
	ft_putptr(ap);
	return (ft_ptrlen(ap));
}

int	ft_put_u(unsigned int ap)
{
	ft_put_unbr_fd(ap, 1);
	return (ft_unbrlen(ap));
}

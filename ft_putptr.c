/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:28:28 by abekri            #+#    #+#             */
/*   Updated: 2024/04/03 02:28:28 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(void *ptr)
{
	unsigned long long	number;

	number = (unsigned long long)ptr;
	ft_putstr_fd1("0x", 1);
	ft_putull_base(number, "0123456789abcdef");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abekri <abekri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 02:28:42 by abekri            #+#    #+#             */
/*   Updated: 2024/04/03 02:28:42 by abekri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_base(char *base)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen2(base);
	if (len <= 1)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putull_base(unsigned long long nbr, char *base)
{
	if (!ft_check_base(base))
		return ;
	if (nbr >= ft_strlen2(base))
		ft_putull_base(nbr / ft_strlen2(base), base);
	write(1, &base[nbr % ft_strlen2(base)], 1);
}

void	ft_putnbr_base(unsigned int nbr, char *base)
{
	if (!ft_check_base(base))
		return ;
	if (nbr >= (unsigned int)ft_strlen2(base))
		ft_putnbr_base(nbr / ft_strlen2(base), base);
	write(1, &base[nbr % ft_strlen2(base)], 1);
}

int	ft_nbrlen_base(unsigned long long n, int base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long) base)
	{
		n = n / base;
		len++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 18:56:59 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/22 18:57:01 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchr(char chr, int *count)
{
	write (2, &chr, 1);
	(*count)++;
}

void	ft_putstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		write (2, "(null)", 6);
		*count += 6;
		return ;
	}
	while (str[i])
		i++;
	write (2, str, i);
	*count += i;
}

void	ft_putnbr(int nb, int *count)
{
	if (nb == -2147483648)
	{
		write (2, "-2147483648", 11);
		*count += 11;
	}
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			ft_putchr('-', count);
			ft_putnbr(nb * -1, count);
		}
		else if (nb >= 10)
		{
			ft_putnbr(nb / 10, count);
			ft_putnbr(nb % 10, count);
		}
		else
			ft_putchr(nb + '0', count);
	}
}

void	ft_uputnbr(unsigned int nb, int *count)
{
	if (nb >= 10)
	{
		ft_uputnbr(nb / 10, count);
		ft_uputnbr(nb % 10, count);
	}
	else
	{
		ft_putchr(nb + '0', count);
	}
}

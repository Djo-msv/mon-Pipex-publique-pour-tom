/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 19:03:15 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/08 13:57:19 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_len(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_recursive(unsigned int nbr, char *base, int *count)
{
	unsigned int	len;

	len = ft_len(base);
	if (nbr >= len)
	{
		ft_recursive(nbr / len, base, count);
		ft_recursive(nbr % len, base, count);
	}
	else
		ft_putchr(base[nbr], count);
}

void	ft_putnbr_hexa(unsigned long nbr, char x, int *count)
{
	char	*base;

	if (x == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_recursive((unsigned int)nbr, base, count);
}

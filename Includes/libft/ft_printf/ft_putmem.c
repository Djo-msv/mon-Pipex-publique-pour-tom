/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:36:52 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/08 13:57:40 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recursivemem(unsigned long nbr, char *base, int *count)
{
	unsigned long	len;

	len = ft_len(base);
	if (nbr >= len)
	{
		ft_recursivemem(nbr / len, base, count);
		ft_recursivemem(nbr % len, base, count);
	}
	else
		ft_putchr(base[nbr], count);
}

void	ft_putmem(unsigned long nbr, int *count)
{
	char	*base;

	base = "0123456789abcdef";
	if (!nbr)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_recursivemem(nbr, base, count);
}

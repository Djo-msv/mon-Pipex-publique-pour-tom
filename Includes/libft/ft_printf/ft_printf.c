/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:19:58 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/08 13:56:39 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*check(char *str, char *to_find, int i)
{
	int	j;
	int	result;

	j = 0;
	result = 0;
	if (str[i] == to_find[j])
	{
		result = 1;
		while (to_find[j])
		{
			if (to_find[j] != str[i + j])
				result = 0;
			j++;
		}
		j = 0;
		if (result == 1)
			return (&str[i]);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (!*to_find)
		return (str);
	while (str[i])
	{
		if (check(str, to_find, i) != 0)
			return (check(str, to_find, i));
		i++;
	}
	return (0);
}

void	typeofprint(const char *format, va_list argptr, int *i, int *count)
{
	(*i)++;
	if (format[*i] == 'c')
		ft_putchr(va_arg(argptr, int), count);
	else if (format[*i] == 's')
		ft_putstr(va_arg(argptr, char *), count);
	else if (format[*i] == 'p')
		ft_putmem(va_arg(argptr, unsigned long), count);
	else if (format[*i] == 'd' || format[*i] == 'i')
		ft_putnbr(va_arg(argptr, int), count);
	else if (format[*i] == 'u')
		ft_uputnbr(va_arg(argptr, unsigned int), count);
	else if (format[*i] == 'x' || format[*i] == 'X')
		ft_putnbr_hexa(va_arg(argptr, unsigned long), format[*i], count);
	else if (format[*i] == '%')
		(*count) += write (2, &format[*i], 1);
	else
		(*count) += write (2, &format[*(i - 1)], 2);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		i;
	int		count;

	if (!format)
		return (-1);
	i = 0;
	count = 0;
	va_start(argptr, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!format[i + 1])
				return (-1);
			typeofprint(format, argptr, &i, &count);
		}
		else
			count += write (2, &format[i], 1);
		i++;
	}
	va_end(argptr);
	return (count);
}

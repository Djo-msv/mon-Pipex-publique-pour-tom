/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 01:26:27 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/23 01:26:34 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

void			ft_putchr(char chr, int *count);
void			ft_putstr(char *str, int *count);
void			ft_putnbr(int nb, int *count);
void			ft_uputnbr(unsigned int nb, int *count);

unsigned int	ft_len(char *str);
void			ft_recursive(unsigned int nbr, char *base, int *count);
void			ft_putnbr_hexa(unsigned long nbr, char x, int *count);

void			ft_recursivemem(unsigned long nbr, char *base, int *count);
void			ft_putmem(unsigned long nbr, int *count);

int				ft_printf(const char *format, ...);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:02:53 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/14 18:28:19 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned int	i;
	unsigned char	*dest_c;
	unsigned char	*src_c;

	dest_c = (unsigned char *) dest;
	src_c = (unsigned char *) src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (dest);
	if (src_c > dest_c)
	{
		while (i < size)
		{
			dest_c[i] = src_c[i];
			i++;
		}
	}
	else
	{
		while (size-- > 0)
			dest_c[size] = src_c[size];
	}
	return (dest_c);
}

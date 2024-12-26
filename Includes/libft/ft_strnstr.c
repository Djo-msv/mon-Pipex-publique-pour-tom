/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:10:29 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/11 16:41:22 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	if ((!big || !little) && !len)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	while (*big && len)
	{
		if (*big == *little)
		{
			size = 0;
			while (big[size] == little[size] && little[size] && len - size > 0)
				size++;
			if (!little[size])
				return ((char *)big);
		}
		big++;
		len--;
	}
	return (NULL);
}

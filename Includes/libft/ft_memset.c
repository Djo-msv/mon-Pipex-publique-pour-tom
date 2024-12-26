/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:16:22 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:16:27 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *mem, int charact, size_t size)
{
	unsigned char	*memory;

	memory = (unsigned char *) mem;
	while (0 < size)
	{
		*memory = (unsigned char) charact;
		memory++;
		size--;
	}
	return (mem);
}

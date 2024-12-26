/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 19:26:22 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:15:03 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *mem, size_t size)
{
	unsigned char	*memory;

	memory = (unsigned char *) mem;
	while (0 < size)
	{
		*memory = '\0';
		memory++;
		size--;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 18:55:23 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:10:56 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	void	*result;

	if (elementCount != 0 && elementSize != 0)
		if (elementCount * elementSize / elementCount != elementSize)
			return (NULL);
	result = malloc(elementCount * elementSize);
	if (!result)
		return (NULL);
	ft_bzero(result, elementCount * elementSize);
	return (result);
}

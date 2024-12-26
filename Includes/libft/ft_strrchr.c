/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:03:07 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/11 19:37:44 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int chr)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	if ((char) chr == '\0')
		return (&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == (char) chr)
			tmp = &str[i];
		i++;
	}
	return (tmp);
}

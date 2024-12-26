/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 15:58:26 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/12 15:58:29 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	len_result;
	unsigned int	i;

	result = NULL;
	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len_result = 0;
	else if (len < ft_strlen(s) - start)
		len_result = len;
	else
		len_result = ft_strlen(s) - start;
	result = malloc((len_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len_result)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

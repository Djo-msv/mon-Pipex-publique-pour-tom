/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:30:13 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/09 17:33:10 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	firstisset(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;

	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static int	lastisset(char const *s1, char const *set)
{
	unsigned long	i;
	unsigned long	j;

	i = ft_strlen(s1) - 1;
	while (i != 0)
	{
		j = 0;
		while (s1[i] != set[j] && set[j] != '\0')
			j++;
		if (set[j] == '\0')
			return (ft_strlen(s1) - i - 1);
		i--;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char const *set)
{
	unsigned int	len_result;
	unsigned int	i;
	char			*result;

	if (s1 == NULL)
		return (NULL);
	if (set[0] == '\0' || set == NULL)
		return (ft_strdup(s1));
	len_result = ft_strlen(s1);
	i = 0;
	len_result -= firstisset(s1, set);
	len_result -= lastisset(s1, set);
	result = malloc((len_result + 1) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < len_result)
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	free (s1);
	return (result);
}

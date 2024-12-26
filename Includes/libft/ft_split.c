/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:48:47 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:16:24 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_split(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	sprnbr(char const *s, char c)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nbr++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (nbr);
}

static void	*freeall(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;
	int		j;
	int		word_p;

	i = 0;
	word_p = 0;
	if (s == NULL)
		return (NULL);
	array = ft_calloc((sprnbr(s, c) + 1), sizeof(char *));
	while (array && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		array[word_p] = ft_calloc(sizeof(char), ft_len_split(&s[i], c) + 1);
		if (!array[word_p])
			return (freeall(array));
		j = -1;
		while (s[i] && s[i] != c)
			array[word_p][++j] = s[i++];
		word_p++;
	}
	return (array);
}

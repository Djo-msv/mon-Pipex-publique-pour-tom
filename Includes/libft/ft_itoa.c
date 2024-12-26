/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 22:25:36 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:14:37 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sizeofn(unsigned int n, char *pnt, int len)
{
	int	l;

	l = 0;
	if (pnt)
		pnt[len--] = '\0';
	while (n >= 10)
	{
		if (pnt)
			pnt[len--] = (char)(n % 10 + '0');
		n = n / 10;
		l++;
	}
	if (pnt)
		pnt[len] = (char)((n % 10) + '0');
	return (l);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	char			*result;
	int				negate;

	negate = 0;
	if (n < 0)
	{
		negate = 1;
		n = n * -1;
	}
	num = (unsigned int)n;
	len = sizeofn(num, NULL, 0) + 1 + negate;
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (negate)
		result[0] = '-';
	sizeofn(num, result, len);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 21:12:04 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:10:41 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int			i;
	int			negate_nb;
	long long	r;

	i = 0;
	negate_nb = 1;
	r = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == 45)
	{
		negate_nb = -negate_nb;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if ((r * 10) + (nptr[i] - '0') <= r && negate_nb < 0 && r != 0)
			return (0);
		else if (r != 0 && (r * 10) + (nptr[i] - '0') <= r)
			return (-1);
		r = (r * 10) + (nptr[i++] - '0');
	}
	return ((int)r * negate_nb);
}

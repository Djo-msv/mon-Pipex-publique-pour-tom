/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <jmassavi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 20:13:55 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/15 15:18:35 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int chr)
{
	if (chr >= 'a' && chr <= 'z')
		chr = chr - 32;
	return (chr);
}
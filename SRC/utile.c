/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:34:59 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/17 11:35:00 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex.h"

char	**dupchar(char **str)
{
	int		i;
	int		j;
	char	**result;

	i = 0;
	while (str[i])
		i++;
	result = ft_calloc(i + 1, sizeof(char *));
	i = 0;
	while (str[i])
	{
		j = 0;
		result[i] = ft_calloc(ft_strlen(str[i]) + 1, sizeof(char));
		while (str[i][j])
		{
			result[i][j] = str[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

char	*ft_joinfree(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*result;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		return (NULL);
	result = ft_calloc(ft_strlen(str1) + ft_strlen(str2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	while (str1[i])
	{
		result[i] = str1[i];
		i++;
	}
	while (str2[j])
		result[i++] = str2[j++];
	free(str1);
	return (result);
}

void	ft_doublefree(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free (str[i]);
		i++;
	}
	free (str);
	str = NULL;
}

void	wait_child(t_vars *cmd)
{
	while (cmd != NULL && cmd->pid != -1)
	{
		while (waitpid(cmd->pid, NULL, 0) != -1)
			continue ;
		cmd = cmd->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 10:39:58 by djo               #+#    #+#             */
/*   Updated: 2024/12/24 19:50:58 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

char	*one_works(char **str, char *cmd)
{
	int		i;
	char	*pathname;

	i = 0;
	if(!cmd)
		return (NULL);
	while (str[i])
	{
		str[i] = ft_joinfree(ft_joinfree(str[i], "/"), cmd);
		i++;
	}
	i = 0;
	while (access(str[i], X_OK) != 0 && str[i + 1])
		i++;
	if (!str[i])
		return (NULL);
	pathname = ft_strdup(str[i]);
	return (pathname);
}

void	make_list(char **str, char **cmd, t_vars **lst)
{
	int				i;
	char			**flag;
	char			*pathname;
	char			**tmp;

	i = 2;
	pathname = NULL;
	while (cmd[i + 1])
	{
		tmp = dupchar(str);
		flag = ft_split(cmd[i], ' ');
		if (flag[0])
		{
			if (access(flag[0], X_OK) == 0)
				pathname = ft_strdup(flag[0]);
			else
				pathname = one_works(tmp, flag[0]);
		}
		else
			ft_printf("Command '' not found \n");
		ft_doublefree (tmp);
		push_back(lst, flag[0], pathname, flag);
		i++;
	}
	ft_doublefree (str);
}

void	parsing(char *str, char **cmd, char **envp, t_vars **lst)
{
	int		i;
	int		j;
	char	**pathname;
	char	*tmp;

	i = 0;
	while (ft_strnstr(envp[i], str, ft_strlen(str)) == NULL)
		i++;
	pathname = ft_split(envp[i], ':');
	if (!pathname)
		return ;
	i = ft_strlen(str);
	tmp = ft_calloc(ft_strlen(pathname[0]) - i + 1, sizeof(char));
	if (!tmp)
	{
		free (pathname);
		return ;
	}
	j = 0;
	while (pathname[0][i])
		tmp[j++] = pathname[0][i++];
	free (pathname[0]);
	pathname[0] = tmp;
	make_list(pathname, cmd, lst);
}

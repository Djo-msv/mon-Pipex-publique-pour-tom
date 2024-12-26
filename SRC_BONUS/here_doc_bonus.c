/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 15:01:53 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/24 18:06:11 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

char	**delarg(int argc, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**array;

	array = ft_calloc(argc + 1, sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	k = 0;
	while (argv[i])
	{
		j = 0;
		if (i != 2)
		{
			array[k] = ft_calloc(ft_strlen(argv[i]) + 1, 1);
			while (argv[i][j])
			{
				array[k][j] = argv[i][j];
				j++;
			}
			k++;
		}
		i++;
	}
	return (array);
}

void	makegnl(char *str)
{
	int		infile;
	char	*line;

	line = NULL;
	infile = open("tmp", O_CREAT | O_WRONLY, 0644);
	while (ft_strncmp(line, str, ft_strlen(str)))
	{
		if (line)
			free (line);
		line = get_next_line(0);
		if (ft_strncmp(line, str, ft_strlen(str)))
			ft_putstr_fd(line, infile);
	}
	free (line);
	close (infile);
}

void	heredoc(t_vars *list, int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	char	**array;

	if (argc >= 6)
	{
		makegnl(argv[2]);
		array = delarg(argc, argv);
		if (!array)
			return ;
		parsing("PATH=", array, envp, &list);
		infile = open ("tmp", O_RDONLY, 0644);
		outfile = open(array[argc - 2], O_CREAT | O_WRONLY | O_APPEND, 0644);
		if (outfile == -1)
			fileko(list, array[argc - 2], 1);
		ft_doublefree(array);
		unlink("tmp");
		exec(list, infile, outfile, envp);
	}
}

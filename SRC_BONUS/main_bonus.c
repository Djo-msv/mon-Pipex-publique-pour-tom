/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:18:03 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/24 15:38:12 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	exec(t_vars *cmd, int in, int out, char **envp)
{
	int		i;
	t_vars	*tmp;

	i = 0;
	tmp = cmd;
	if (makes_pipes(in, out, cmd) == -1)
		pop_all(&cmd);
	while (cmd)
	{
		cmd->pid = fork();
		if (cmd->pid == 0)
			child_process(cmd, tmp, envp);
		close (cmd->in);
		close (cmd->out);
		cmd->out = -2;
		cmd->in = -2;
		if (cmd->pid == -1)
			break ;
		cmd = cmd->next;
		i++;
	}
	wait_child(tmp);
	pop_all(&tmp);
}

void	fileko(t_vars *lst, char *str, int position)
{
	if (position == 1)
	{
		while (lst->next)
			lst = lst->next;
	}
	ft_printf("%s: %s\n", strerror(errno), str);
	free (lst->pathname);
	lst->pathname = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	int				infile;
	int				outfile;
	t_vars			*list;

	list = NULL;
	if (!ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc")))
		heredoc(list, argc, argv, envp);
	else
	{
		if (argc >= 5)
		{
			parsing("PATH=", argv, envp, &list);
			infile = open(argv[1], O_RDONLY, 0644);
			if (infile == -1)
				fileko(list, argv[1], 0);
			outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
			if (outfile == -1)
				fileko(list, argv[argc - 1], 1);
			exec(list, infile, outfile, envp);
		}
	}
	return (0);
}

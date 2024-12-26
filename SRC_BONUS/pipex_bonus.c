/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:55:01 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/24 17:52:31 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

void	close_all(t_vars *cmd)
{
	while (cmd && cmd->in != -1)
	{
		if (cmd->in != -2)
			close (cmd->in);
		if (cmd->out != -2)
			close (cmd->out);
		cmd = cmd->next;
	}
}

void	child_process(t_vars *cmd, t_vars *head, char **envp)
{
	t_vars	*tmp;

	tmp = head;
	dup2(cmd->in, STDIN_FILENO);
	dup2(cmd->out, STDOUT_FILENO);
	close_all(tmp);
	if (cmd->pathname != NULL)
		execve(cmd->pathname, cmd->flag, envp);
	if (cmd->cmd != NULL && cmd->pathname != NULL)
		ft_printf("%s: %s\n", "Command not found", cmd->cmd);
	exit(1);
}

void	put_ltl_pipe(t_vars *cmd, int in, int *fd)
{
	cmd->in = in;
	cmd->out = fd[1];
	cmd->next_in = fd[0];
}

int	put_pipe(t_vars *cmd, int icmd, int in, int out)
{
	static int	fd[2048][2];

	if (cmd->next)
	{
		if (pipe(fd[icmd]) == -1)
			return (-1);
	}
	if (icmd != 0)
	{
		cmd->prev_out = fd[icmd - 1][1];
		cmd->in = fd[icmd - 1][0];
		if (cmd->next)
		{
			cmd->out = fd[icmd][1];
			cmd->next_in = fd[icmd][0];
		}
		else
			cmd->out = out;
	}
	else
		put_ltl_pipe(cmd, in, fd[icmd]);
	return (0);
}

int	makes_pipes(int in, int out, t_vars *cmd)
{
	int		i;
	t_vars	*tmp;

	i = 0;
	tmp = cmd;
	while (cmd)
	{
		if (put_pipe(cmd, i, in, out) == -1)
		{
			close_all(tmp);
			pop_all(&tmp);
			perror("pipe error");
			exit(1);
		}
		i++;
		cmd = cmd->next;
	}
	return (0);
}

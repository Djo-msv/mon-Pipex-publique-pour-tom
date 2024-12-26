/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 11:11:18 by jmassavi          #+#    #+#             */
/*   Updated: 2024/12/08 15:44:57 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

typedef struct s_vars
{
	char			*cmd;
	char			*pathname;
	char			**flag;

	int				prev_out;
	int				in;
	int				out;
	int				next_in;

	int				pid;

	struct s_vars	*next;
}	t_vars;

void	child_process(t_vars *cmd, t_vars *head, char **envp);
int		put_pipe(t_vars *cmd, int icmd, int in, int out);
int		makes_pipes(int in, int out, t_vars *cmd);

void	fileko(t_vars *lst, char *str, int position);
void	exec(t_vars *cmd, int in, int out, char **envp);

void	parsing(char *str, char **cmd, char **envp, t_vars **lst);

char	**dupchar(char **str);
char	*ft_joinfree(char *str1, char *str2);
void	ft_doublefree(char **str);
void	wait_child(t_vars *cmd);

void	push_back(t_vars **head, char *cmd, char *pathname, char **flag);
void	pop_all(t_vars **head);

void	heredoc(t_vars *list, int argc, char **argv, char **envp);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djo <djo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 08:59:59 by djo               #+#    #+#             */
/*   Updated: 2024/12/08 14:47:58 by djo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/pipex_bonus.h"

struct s_vars	*create_node(char *cmd, char *pathname, char **flag)
{
	struct s_vars	*new_node;

	new_node = malloc(sizeof(struct s_vars));
	if (!new_node)
		return (NULL);
	new_node->cmd = cmd;
	new_node->pathname = pathname;
	new_node->flag = flag;
	new_node->prev_out = -1;
	new_node->in = -1;
	new_node->out = -1;
	new_node->next_in = -1;
	new_node->pid = -1;
	new_node->next = NULL;
	return (new_node);
}

void	push_back(struct s_vars **head, char *cmd, char *pathname, char **flag)
{
	struct s_vars	*new_node;
	struct s_vars	*current;

	new_node = create_node(cmd, pathname, flag);
	if (!new_node)
		return ;
	if (*head == NULL)
	{
		*head = new_node;
		return ;
	}
	current = *head;
	while (current->next)
		current = current->next;
	current->next = new_node;
}

void	pop_front(struct s_vars **head)
{
	struct s_vars	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	*head = (*head)->next;
	free(tmp->pathname);
	ft_doublefree(tmp->flag);
	free(tmp);
}

void	pop_all(struct s_vars **head)
{
	struct s_vars	*tmp;

	if (!*head)
		return ;
	tmp = *head;
	while ((*head))
	{
		*head = (*head)->next;
		pop_front(&tmp);
	}
}

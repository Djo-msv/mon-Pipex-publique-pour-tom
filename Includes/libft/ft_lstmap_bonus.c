/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmassavi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:21:16 by jmassavi          #+#    #+#             */
/*   Updated: 2024/10/17 14:21:17 by jmassavi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*newlst;
	void	*cont;

	tmp = NULL;
	newlst = NULL;
	cont = NULL;
	if (!lst || !(*f) || !(*del))
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		if (cont)
			tmp = ft_lstnew(cont);
		if (!tmp || !cont)
		{
			if (cont)
				del(cont);
			ft_lstclear(&newlst, (*del));
			return (NULL);
		}
		ft_lstadd_back(&newlst, tmp);
		lst = lst->next;
	}
	return (newlst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:46:55 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:44 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_new;
	t_list	*new;
	void	*tmp;

	begin_new = NULL;
	while (lst != NULL)
	{
		tmp = f(lst->content);
		new = ft_lstnew(tmp);
		if (new == NULL)
		{
			if (begin_new != NULL)
				ft_lstclear(&begin_new, del);
			del(tmp);
			return (NULL);
		}
		ft_lstadd_back(&begin_new, new);
		lst = lst->next;
	}
	return (begin_new);
}

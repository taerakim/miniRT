/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:35:30 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:31 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	next = tmp->next;
	while (tmp->next != NULL)
	{
		del(tmp->content);
		free(tmp);
		tmp = next;
		next = next->next;
	}
	del(tmp->content);
	free(tmp);
	*lst = NULL;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:24:57 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:46:50 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = lst;
	while (tmp != NULL)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}

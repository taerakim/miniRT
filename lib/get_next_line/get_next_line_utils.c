/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:11 by taerakim          #+#    #+#             */
/*   Updated: 2023/12/20 18:49:28 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	manage_fd_node(t_file **curr, int fd)
{
	t_file	*new;

	while (*curr != NULL)
	{
		if (fd == (*curr)->fd)
			return ;
		if (fd < (*curr)->fd)
		{
			if ((*curr)->prev == NULL || (*curr)->prev->fd < fd)
				break ;
			*curr = (*curr)->prev;
		}
		else if ((*curr)->fd < fd)
		{
			if ((*curr)->next == NULL || fd < (*curr)->next->fd)
				break ;
			*curr = (*curr)->next;
		}
	}
	new = (t_file *)ft_calloc(sizeof(t_file), 1);
	new->fd = fd;
	if (*curr == NULL)
		*curr = new;
	else
		connect_node(curr, fd, new);
}

void	connect_node(t_file **curr, int fd, t_file *new)
{
	if (fd < (*curr)->fd)
	{
		if ((*curr)->prev != NULL)
		{
			new->prev = (*curr)->prev;
			(*curr)->prev->next = new;
		}
		new->next = *curr;
		(*curr)->prev = new;
	}
	else if ((*curr)->fd < fd)
	{
		if ((*curr)->next != NULL)
		{
			new->next = (*curr)->next;
			(*curr)->next->prev = new;
		}
		new->prev = *curr;
		(*curr)->next = new;
	}
	*curr = new;
}

void	delete_all_node(t_file **curr)
{
	t_file	*tmp_fdnode;
	t_buf	*tmp_bufnode;

	while ((*curr)->save != NULL)
	{
		tmp_bufnode = (*curr)->save;
		(*curr)->save = (*curr)->save->next;
		free(tmp_bufnode);
	}
	tmp_fdnode = *curr;
	if ((*curr)->prev == NULL && (*curr)->next == NULL)
		*curr = NULL;
	else
	{
		if (tmp_fdnode->prev != NULL)
			tmp_fdnode->prev->next = tmp_fdnode->next;
		if (tmp_fdnode->next != NULL)
			tmp_fdnode->next->prev = tmp_fdnode->prev;
		if (tmp_fdnode->prev != NULL)
			*curr = tmp_fdnode->prev;
		if (tmp_fdnode->next != NULL)
			*curr = tmp_fdnode->next;
	}
	free(tmp_fdnode);
}

void	check_newline(t_buf *bufnode, bool *nl_flag)
{
	size_t	iter;

	if (*nl_flag == true)
		bufnode->idx[0] = bufnode->idx[1] + 1;
	iter = bufnode->idx[0];
	*nl_flag = false;
	while (bufnode->buffer[iter] != '\0')
	{
		if (bufnode->buffer[iter] == '\n')
		{
			bufnode->idx[1] = iter;
			*nl_flag = true;
			return ;
		}
		iter++;
	}
	bufnode->idx[1] = iter;
}

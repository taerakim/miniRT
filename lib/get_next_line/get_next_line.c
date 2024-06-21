/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:07 by taerakim          #+#    #+#             */
/*   Updated: 2023/12/20 18:58:37 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static t_file	*curr;
	t_buf			*dummybuf;
	char			*res;

	manage_fd_node(&curr, fd);
	if (read(fd, NULL, 0) < 0)
	{
		delete_all_node(&curr);
		return (NULL);
	}
	if (curr->save == NULL)
	{
		dummybuf = (t_buf *)ft_calloc(sizeof(t_buf), 1);
		curr->save = dummybuf;
	}
	if (curr->nl_flag == true)
		res = get_one_line(&curr->save, &curr->nl_flag);
	else
		res = read_file(fd, &curr);
	return (res);
}

char	*read_file(int fd, t_file **curr)
{
	t_buf	*bufnode;
	char	*res;
	int		result;

	bufnode = (*curr)->save;
	if ((*curr)->save->next != NULL)
		bufnode = (*curr)->save->next;
	while ((*curr)->nl_flag != true)
	{
		result = read_to_buf(fd, bufnode, &(*curr)->nl_flag);
		if (result == EOF_READ || result == ERROR)
		{
			if (result == EOF_READ && (*curr)->save->next != NULL)
				res = get_one_line(&(*curr)->save, &(*curr)->nl_flag);
			else
				res = NULL;
			delete_all_node(curr);
			return (res);
		}
		bufnode = bufnode->next;
	}
	res = get_one_line(&(*curr)->save, &(*curr)->nl_flag);
	return (res);
}

int	read_to_buf(int fd, t_buf *bufnode, bool *nl_flag)
{
	t_buf	*new;
	ssize_t	read_result;

	new = (t_buf *)ft_calloc(sizeof(t_buf), 1);
	read_result = read(fd, new->buffer, BUFFER_SIZE);
	if (read_result <= 0)
	{
		free(new);
		if (read_result == 0)
			return (EOF_READ);
		if (read_result < 0)
			return (ERROR);
	}
	if (read_result > 0)
	{
		check_newline(new, nl_flag);
		bufnode->next = new;
		return (VALID_READ);
	}
	return (0);
}

char	*get_one_line(t_buf **head, bool *nl_flag)
{
	t_buf	*bufnode;
	size_t	total_len;
	char	*res;

	bufnode = (*head)->next;
	total_len = 0;
	if (*nl_flag == true)
		total_len += 1;
	while (bufnode != NULL)
	{
		total_len += bufnode->idx[1] - bufnode->idx[0];
		bufnode = bufnode->next;
	}
	if (total_len == 0)
		return (NULL);
	res = buf_to_str(head, (*head)->next, total_len, nl_flag);
	if ((*head)->next != NULL)
		check_newline((*head)->next, nl_flag);
	else
		*nl_flag = false;
	return (res);
}

char	*buf_to_str(t_buf **head, t_buf *bufnode, size_t len, bool *nl_flag)
{
	t_buf	*tmp;
	char	*res;
	size_t	idx;
	size_t	total;

	res = (char *)ft_calloc(sizeof(char) * (len + 1), 1);
	total = 0;
	while (bufnode != NULL)
	{
		idx = bufnode->idx[0];
		while (idx < bufnode->idx[1])
			res[total++] = bufnode->buffer[idx++];
		if (bufnode->idx[1] < BUFFER_SIZE - 1 && bufnode->buffer[idx] != '\0')
			break ;
		tmp = bufnode;
		bufnode = bufnode->next;
		free(tmp);
	}
	if (*nl_flag == true)
		res[len - 1] = '\n';
	(*head)->next = bufnode;
	return (res);
}

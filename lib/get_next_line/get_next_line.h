/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 14:33:02 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/10 09:31:30 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* ******************************* INCLUDE ********************************** */
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

/* ONLY! ft_malloc & ft_calloc */
# include "libft.h"

/* ******************************** MACRO *********************************** */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# define VALID_READ 1
# define EOF_READ 2
# define ERROR -1
# define MALLOC_ERROR -20

/* ************************ USER DEFINED STRUCTURE ************************** */
typedef struct s_buf
{
	size_t			idx[2];
	char			buffer[BUFFER_SIZE + 1];
	struct s_buf	*next;
}					t_buf;

typedef struct s_file
{
	int				fd;
	bool			nl_flag;
	struct s_buf	*save;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

/* ******************************* FUNCTIONS ******************************** */
/* get_next_line_bonus.c */
char	*get_next_line(int fd);
char	*read_file(int fd, t_file **curr);
int		read_to_buf(int fd, t_buf *curr_buf, bool *nl_flag);
char	*get_one_line(t_buf **head, bool *nl_flag);
char	*buf_to_str(t_buf **head, t_buf *bufnode, size_t len, bool *nl_flag);
/* get_next_line_utils_bonus.c */
int		manage_fd_node(t_file **curr, int fd);
void	connect_node(t_file **curr, int fd, t_file *new);
void	delete_all_node(t_file **curr);
void	check_newline(t_buf *bufnode, bool *nl_flag);

#endif

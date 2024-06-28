/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:18:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 16:54:40 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse_bonus.h"
#include "ft_error_bonus.h"

int	ft_getline_count(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	return (count);
}

void	create_object(t_object **head, char **vals)
{
	t_object	*ptr;
	t_object	*new;

	new = NULL;
	if (ft_strncmp(vals[0], "pl", 3) == 0)
		new = create_plane(&vals[1]);
	else if (ft_strncmp(vals[0], "sp", 3) == 0)
		new = create_sphere(&vals[1]);
	else if (ft_strncmp(vals[0], "cy", 3) == 0)
		new = create_cylinder(&vals[1]);
	else if (ft_strncmp(vals[0], "co", 3) == 0)
		new = create_cone(&vals[1]);
	else
		ft_error(error_file_format);
	if (!new)
		return ;
	ptr = *head;
	if (ptr == NULL)
	{
		*head = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	parse_to_obj(t_element *element, char **obj_args, bool *init_flag)
{
	if (ft_strncmp(obj_args[0], "A", 2) == 0)
	{
		if (init_flag[0] == false)
		{
			element->ambient = create_ambient(&obj_args[1]);
			init_flag[0] = true;
		}
		else
			ft_error(error_file_format);
	}
	else if (ft_strncmp(obj_args[0], "C", 2) == 0)
	{
		if (init_flag[1] == false)
		{
			element->camera = create_camera(&obj_args[1]);
			init_flag[1] = true;
		}
		else
			ft_error(error_file_format);
	}
	else if (ft_strncmp(obj_args[0], "L", 2) == 0)
		create_light(&element->light, &obj_args[1]);
	else
		create_object(&element->objs, obj_args);
}

t_element	ft_parse_rt(int fd)
{
	t_element	obj;
	bool		init_flag[2];
	char		*line;
	char		**obj_args;

	ft_memset(&obj, 0, sizeof(t_element));
	ft_memset(init_flag, 0, sizeof(bool) * 2);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '#')
		{
			obj_args = rt_split(line);
			if (obj_args != NULL)
			{
				parse_to_obj(&obj, obj_args, init_flag);
				ft_clear_char(obj_args);
			}
		}
		free(line);
		line = get_next_line(fd);
	}
	return (obj);
}

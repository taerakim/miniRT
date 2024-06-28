/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:18:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/27 22:11:09 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"

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
	if (ft_strncmp(vals[0], "sp", 3) == 0)
		new = create_sphere(&vals[1]);
	if (ft_strncmp(vals[0], "cy", 3) == 0)
		new = create_cylinder(&vals[1]);
	if (ft_strncmp(vals[0], "co", 3) == 0)
		new = create_cone(&vals[1]);
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

void	parse_to_obj(t_element *element, char *line)
{
	char	**obj_args;

	obj_args = rt_split(line);
	if (obj_args == NULL)
		return ;
	if (ft_strncmp(obj_args[0], "#", 2) == 0)
	{
		ft_clear_char(obj_args);
		return ;
	}
	if (ft_strncmp(obj_args[0], "A", 2) == 0)
		element->ambient = create_ambient(&obj_args[1]);
	else if (ft_strncmp(obj_args[0], "L", 2) == 0)
		create_light(&element->light, &obj_args[1]);
	else if (ft_strncmp(obj_args[0], "C", 2) == 0)
		element->camera = create_camera(&obj_args[1]);
	else
		create_object(&element->objs, obj_args);
	ft_clear_char(obj_args);
}

t_element	ft_parse_rt(int fd)
{
	t_element	obj;
	char		*line;

	obj.objs = NULL;
	obj.light = NULL;
	line = get_next_line(fd);
	while (line)
	{
		parse_to_obj(&obj, line);
		free(line);
		line = get_next_line(fd);
	}
	return (obj);
}

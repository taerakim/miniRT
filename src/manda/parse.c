/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:18:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/19 16:25:49 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	if (ft_strncmp(vals[0], "pl", 3) == 0)
		ptr->next = create_plane(&vals[1]);
	if (ft_strncmp(vals[0], "sp", 3) == 0)
		ptr->next = create_sphere(&vals[1]);
	if (ft_strncmp(vals[0], "cy", 3) == 0)
		ptr->next = create_cylinder(&vals[1]);
}

void	parse_to_obj(t_element *element, char *line)
{
	char	**obj_args;

	obj_args = ft_split(line, ' ');
	if (obj_args == NULL)
		return ;
	if (ft_strncmp(obj_args[0], "A", 2) == 0)
		element->ambient = create_ambient(&obj_args[1]);
	else if (ft_strncmp(obj_args[0], "L", 2) == 0)
		element->light = create_light(&obj_args[1]);
	else if (ft_strncmp(obj_args[0], "C", 2) == 0)
		element->camera = create_camera(&obj_args[1]);
	else
		create_object(&element->objs, obj_args);
}

t_element	ft_parse_rt(t_list **llist, int fd)
{
	t_element	obj;
	char		*line;

	obj.objs = NULL;
	line = get_next_line(fd);
	while (line)
	{
		parse_to_obj(&obj, line);
		free(line);
		line = get_next_line(fd);
	}
	return (obj);
}

int	main(int argc, char **argv)
{
	argc = 0;
	argv = 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 22:18:30 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/18 22:47:48 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

typedef struct s_obj
{
	char	*type;

	double	*pos;
	double	*nvec; // pl, cy
	double	*rgb;
	double	ratio; // A, L
	double	diameter; // cy, sp
	double	height; //cy
	int		fov; //c

}	t_obj;

typedef struct s_list
{
	t_obj	*obj;
	void	*next;
}	t_list;

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

t_obj	*create_ambient_node(char **obj_args)
{
	t_obj	*obj;
	char	**rgb;

	obj = malloc(sizeof(t_obj));
	if (obj == NULL);
	obj->type = ft_strdup(obj_args[0]);
	obj->ratio = atod(obj_args[1]);
	obj->rgb = malloc(sizeof(double) * 3);
	if (obj->rgb == NULL)
		return ;
	rgb = ft_split(obj_args[2], ',');
	obj->rgb[0] = atod(rgb[0]);
	obj->rgb[1] = atod(rgb[1]);
	obj->rgb[2] = atod(rgb[2]);
	return (obj);
}

void	add_to_list(t_list **llist, void *obj)
{
	t_list	*ptr;

	ptr = *llist;
	while (ptr)
		ptr = ptr->next;
	ptr->next = obj;
}

void	parse_to_obj(t_list **llist, char *line)
{
	char	**obj_args;
	t_obj	*obj;

	obj_args = ft_split(line, ' ');
	if (obj_args == NULL)
		return ;
	if (ft_strncmp(obj_args[0], "A", 2) == 0)
		add_to_list(llist, create_ambient_node(obj_args));
}

int	ft_parse_rt(t_list **llist, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		parse_to_obj(llist, line);
		free(line);
		line = get_next_line(fd);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	
}

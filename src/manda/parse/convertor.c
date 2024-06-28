/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:09 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/24 20:57:26 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
#include "ft_error.h"
#include "vector.h"

t_vec	vec(char *vec)
{
	t_vec	obj;
	char	**val;

	val = ft_split(vec, ',');
	if (arg_len(val) != 3)
		ft_error(error_init);
	atod(val[0], &obj.x);
	atod(val[1], &obj.y);
	atod(val[2], &obj.z);
	return (vunit(obj));
}

t_point	point(char *pos)
{
	t_point	obj;
	char	**point;

	point = ft_split(pos, ',');
	if (arg_len(point) != 3)
		ft_error(error_file_format);
	atod(point[0], &obj.x);
	atod(point[1], &obj.y);
	atod(point[2], &obj.z);
	return (obj);
}

t_color	color(char *rgb)
{
	t_color	obj;
	char	**color;

	color = ft_split(rgb, ',');
	if (arg_len(color) != 3)
		ft_error(error_file_format);
	atod(color[0], &obj.x);
	atod(color[1], &obj.y);
	atod(color[2], &obj.z);
	return (obj);
}

t_ambient	create_ambient(char **vals)
{
	t_ambient	amb;

	if (arg_len(vals) != 2)
		ft_error(error_init);
	atod(vals[0], &amb.ratio);
	amb.rgb = color(vals[1]);
	return (amb);
}

t_light	create_light(char **vals)
{
	t_light	light;

	if (arg_len(vals) < 2 && arg_len(vals) < 4)
		ft_error(error_init);
	light.point = point(vals[0]);
	atod(vals[1], &light.ratio);
	return (light);
}

t_camera	create_camera(char **vals)
{
	t_camera	camera;

	if (arg_len(vals) != 3)
		ft_error(error_init);
	camera.point = point(vals[0]);
	camera.nvec = vec(vals[1]);
	atod(vals[2], &camera.fov);
	return (camera);
}

t_object	*create_sphere(char **vals)
{
	t_object	*obj;

	if (arg_len(vals) != 3)
		return (NULL);
	obj = ft_malloc(sizeof(t_object));
	obj->type = type_sphere;
	obj->point = point(vals[0]);
	atod(vals[1], &obj->diameter);
	obj->rgb = color(vals[2]);
	obj->next = NULL;
	return (obj);
}

t_object	*create_plane(char **vals)
{
	t_object	*obj;

	if (arg_len(vals) != 3)
		return (NULL);
	obj = ft_malloc(sizeof(t_object));
	obj->type = type_plane;
	obj->point = point(vals[0]);
	obj->nvec = vec(vals[1]);
	obj->rgb = color(vals[2]);
	obj->next = NULL;
	return (obj);
}

t_object	*create_cylinder(char **vals)
{
	t_object	*obj;

	if (arg_len(vals) != 5)
		return (NULL);
	obj = ft_malloc(sizeof(t_object));
	obj->type = type_cylinder;
	obj->point = point(vals[0]);
	obj->nvec = vec(vals[1]);
	atod(vals[2], &obj->diameter);
	atod(vals[3], &obj->height);
	obj->rgb = color(vals[4]);
	obj->next = NULL;
	return (obj);
}

int	arg_len(char **vals)
{
	int	i;

	if (vals == NULL)
		return (0);
	i = 0;
	while (vals[i])
		i++;
	return (i);
}

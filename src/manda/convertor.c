/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:09 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/19 16:24:23 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vec	convert_vec(char *vec)
{
	t_vec	obj;
	char	**val;

	val = ft_split(vec, ',');
	//nullguard
	obj.x = atod(val[0]);
	obj.y = atod(val[1]);
	obj.z = atod(val[2]);
	return (obj);
}

t_point	convert_point(char *pos)
{
	t_point	obj;
	char	**point;

	point = ft_split(pos, ',');
	//nullguard
	obj.x = atod(point[0]);
	obj.y = atod(point[1]);
	obj.z = atod(point[2]);
	return (obj);
}

t_color	convert_color(char *rgb)
{
	t_color	obj;
	char	**color;

	color = ft_split(rgb, ',');
	//nullguard
	obj.r = atod(color[0]);
	obj.g = atod(color[1]);
	obj.b = atod(color[2]);
	return (obj);
}

t_ambient	create_ambient(char **vals)
{
	t_ambient	amb;

	amb.ratio = atod(vals[0]);
	amb.rgb = convert_color(vals[1]);
	return (amb);
}

t_light	create_light(char **vals)
{
	t_light	light;

	light.point = convert_point(vals[0]);
	light.ratio = atod(vals[1]);
	return (light);
}

t_camera	create_camera(char **vals)
{
	t_camera	camera;

	camera.point = convert_point(vals[0]);
	camera.nvec = convert_vec(vals[1]);
	camera.fov = ft_atoi(vals[2]);
	return (camera);
}

t_object	*create_sphere(char **vals)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = sphere;
	obj->point = convert_point(vals[0]);
	obj->diameter = atod(vals[1]);
	obj->rgb = convert_color(vals[2]);
	obj->next = NULL;
	return (obj);
}

t_object	*create_plane(char **vals)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = plane;
	obj->point = convert_point(vals[0]);
	obj->nvec = convert_vec(vals[1]);
	obj->rgb = convert_color(vals[2]);
	obj->next = NULL;
	return (obj);
}

t_object	*create_cylinder(char **vals)
{
	t_object	*obj;

	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = cylinder;
	obj->point = convert_point(vals[0]);
	obj->nvec = convert_vec(vals[1]);
	obj->diameter = atod(vals[2]);
	obj->height = atod(vals[3]);
	obj->rgb = convert_color(vals[4]);
	obj->next = NULL;
	return (obj);
}


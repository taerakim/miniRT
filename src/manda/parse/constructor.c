/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 21:56:17 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:52:23 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"
#include "vector.h"
#include "ft_error.h"

t_camera	create_camera(char **vals)
{
	t_camera	camera;

	if (arg_len(vals) != 3)
		ft_error(error_init);
	camera.point = point(vals[0]);
	camera.nvec = vec(vals[1]);
	atod(vals[2], &camera.fov);
	if (0 > camera.fov || 255 < camera.fov)
		ft_error(error_file_format);
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

t_object	*create_cone(char **vals)
{
	t_object	*obj;

	if (arg_len(vals) != 5)
		return (NULL);
	obj = ft_malloc(sizeof(t_object));
	obj->type = type_cone;
	obj->point = point(vals[0]);
	obj->nvec = vec(vals[1]);
	atod(vals[2], &obj->diameter);
	atod(vals[3], &obj->height);
	obj->rgb = color(vals[4]);
	obj->next = NULL;
	return (obj);
}

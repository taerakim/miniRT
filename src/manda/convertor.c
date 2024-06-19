/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:09 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/19 21:38:02 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

t_vec	vec(char *vec)
{
	t_vec	obj;
	char	**val;

	val = ft_split(vec, ',');
	if (arg_len(val) != 3)
		init_error();
	//nullguard
	atod(val[0], &obj.x);
	atod(val[1], &obj.y);
	atod(val[2], &obj.z);
	return (obj);
}

t_point	point(char *pos)
{
	t_point	obj;
	char	**point;

	point = ft_split(pos, ',');
	if (arg_len(point) != 3)
		init_error();
	//nullguard
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
		init_error();
	//nullguard
	atod(color[0], &obj.r);
	atod(color[1], &obj.g);
	atod(color[2], &obj.b);
	return (obj);
}

t_ambient	create_ambient(char **vals)
{
	t_ambient	amb;

	if (arg_len(vals) != 2)
		init_error();
	atod(vals[0], &amb.ratio);
	amb.rgb = color(vals[1]);
	return (amb);
}

t_light	create_light(char **vals)
{
	t_light	light;

	if (arg_len(vals) < 2 && arg_len(vals) < 4)
		init_error();
	light.point = point(vals[0]);
	atod(vals[1], &light.ratio);
	return (light);
}

t_camera	create_camera(char **vals)
{
	t_camera	camera;

	if (arg_len(vals) != 3)
		init_error();
	camera.point = point(vals[0]);
	camera.nvec = vec(vals[1]);
	camera.fov = ft_atoi(vals[2]);
	return (camera);
}

t_object	*create_sphere(char **vals)
{
	t_object	*obj;

	if (arg_len(vals) != 3)
		return (NULL);
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = sphere;
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
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = plane;
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
	obj = malloc(sizeof(t_object));
	if (obj == NULL)
		return (NULL);
	obj->type = cylinder;
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

	i = 0;
	while (vals[i])
		i++;
	return (i);
}

void	init_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}


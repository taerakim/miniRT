/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 16:34:55 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_struct.h"
#include "vector.h"

void	_check_front(t_vec ray, t_hit *record)
{
	if (vec_inner(ray, record->nvec) < 0)
		record->isfront = true;
	else
	{
		record->isfront = false;
		record->nvec = vec_multi_scala(record->nvec, -1);
	}
}

bool	hit_cylinder(t_camera *camera, t_object *cylinder, t_vec ray)
{
	const t_vec		ce = vec_subtraction(camera->point, \
						vec_addtion(vec_multi_scala(cylinder->nvec \
						, -1 * (cylinder->height / 2)), cylinder->point));
	const double	a = pow(vec_inner(ray, cylinder->nvec), 2) - 1;
	const double	b = vec_inner(ray, cylinder->nvec) \
						* vec_inner(ce, cylinder->nvec) \
						- vec_inner(ce, ray);;
	const double	c = pow(cylinder->diameter / 2, 2) - vec_inner(ce, ce) \
						+ pow(vec_inner(ce, cylinder->nvec), 2);
	const double	det = pow(b, 2) - a * c;

	if (det < 0)
		return (false);
	return (true);
}

bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray, t_hit *record)
{
	const double	a = vec_inner(ray, ray);
	const double	b = vec_inner(vec_subtraction(camera->point, sphere->point)\
								, ray);
	const double	c = vec_inner(vec_subtraction(camera->point, sphere->point)\
								, vec_subtraction(camera->point\
												, sphere->point))\
						- sphere->diameter;
	const double	discriminant = b * b - a * c;
	double			sqrted;
	double			root;

	if (discriminant < 0)
		return (false);
	sqrted = sqrt(discriminant);
	root = (sqrted - b) / a;
	if (root < record->tmin || record->tmax < root)
	{
		root = (sqrted - b) / a;
		if (root < record->tmin || record->tmax < root)
			return (false);
	}
	record->t = root;
	record->p = vec_addtion(camera->point, vec_multi_scala(ray, root));
	record->nvec = vec_divi_scala(vec_subtraction(record->p, sphere->point)\
								, sphere->diameter);
	
	_check_front(ray, record);
	return (true);
}

bool	hit_plane(t_object *plane, t_vec ray)
{
	if (vec_inner(ray, plane->nvec) < 0)
		return (true);
	return (false);
}

// 모든 object에 대해 type을 확인하고 각기 실행해주는 함수
bool	hit_object(t_camera *camera, t_object *objs, t_vec ray, t_hit *record)
{
	if (objs->type == type_sphere)
		return (hit_sphere(camera, objs, ray, record));
	if (objs->type == type_plane)
		return (hit_plane(objs, ray));
	if (objs->type == type_cylinder)
		return (hit_cylinder(camera, objs, ray));
	return (false);
}

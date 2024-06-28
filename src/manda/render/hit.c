/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 16:51:04 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

void	_check_front(t_vec ray, t_hit *record)
{
	if (vinner(ray, record->nvec) < 0)
		record->isfront = true;
	else
	{
		record->nvec = vunit(vmulti_s(record->nvec, -1));
		record->isfront = false;
	}
}

bool	hit_sphere(t_point camera, t_object *sphere, t_vec ray, t_hit *record)
{
	const t_det	ans = det(1, vinner(ray, vminus(camera, sphere->point)), \
	vinner(vminus(camera, sphere->point), \
	vminus(camera, sphere->point)) - pow(sphere->diameter / 2, 2));

	if (ans.det < 0)
		return (false);
	if (ans.t < record->tmin || record->tmax < ans.t)
		return (false);
	record->t = ans.t;
	record->ishit = true;
	record->tmax = record->t;
	record->p = vplus(camera, vmulti_s(ray, ans.t));
	record->nvec = vunit(vminus(record->p, sphere->point));
	record->object = *sphere;
	return (true);
}

bool	hit_plane(t_point camera, t_object *plane, t_vec ray, t_hit *record)
{
	const t_vec	ea = vminus(plane->point, camera);
	double		t;

	t = vinner(ea, plane->nvec) / vinner(ray, plane->nvec);
	if (-EPSILON < vinner(ray, plane->nvec) \
	&& vinner(ray, plane->nvec) < EPSILON)
		return (false);
	if (t < record->tmin || record->tmax < t)
		return (false);
	record->t = t;
	record->ishit = true;
	record->tmax = record->t;
	record->p = vplus(camera, vmulti_s(ray, t));
	record->nvec = plane->nvec;
	record->object = *plane;
	return (true);
}

bool	hit_object(t_point origin, t_object **objs, t_vec ray, t_hit *record)
{
	t_object	*ptr;

	ptr = *objs;
	while (ptr)
	{
		if (ptr->type == type_sphere)
			hit_sphere(origin, ptr, ray, record);
		if (ptr->type == type_plane)
			hit_plane(origin, ptr, ray, record);
		if (ptr->type == type_cylinder)
			hit_cylinder(origin, ptr, ray, record);
		if (ptr->type == type_cone)
			hit_cone(origin, ptr, ray, record);
		ptr = ptr->next;
	}
	return (record->ishit);
}

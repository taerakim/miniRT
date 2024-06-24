/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/24 19:40:17 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_struct.h"
#include "vector.h"
#include "minirt.h"

void	_check_front(t_vec ray, t_hit *record)
{
	if (vinner(ray, record->nvec) < 0)
		record->isfront = true;
	else
	{
		record->isfront = false;
		record->nvec = vunit(vmulti_s(record->nvec, -1));
	}
}

bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray, t_hit *record)
{
	const t_det	ans = det(1, vinner(ray, vminus(camera->point, sphere->point)), \
	vinner(vminus(camera->point, sphere->point), \
	vminus(camera->point, sphere->point)) - pow(sphere->diameter / 2, 2));

	if (ans.det < 0)
		return (false);
	if (ans.t < record->tmin || record->tmax < ans.t)
		return (false);
	record->t = ans.t;
	record->tmax = ans.t;
	record->p = vplus(camera->point, vmulti_s(ray, ans.t));
	record->nvec = vunit(vdivi_s(vminus(record->p, sphere->point) \
								, sphere->diameter / 2));
	_check_front(ray, record);
	return (true);
}

bool	hit_plane(t_camera *camera, t_object *plane, t_vec ray, t_hit *record)
{
	const t_vec	ea = vminus(plane->point, camera->point);
	double		t;

	if (vinner(ray, plane->nvec) == 0)
		return (false);
	t = vinner(ea, plane->nvec) / vinner(ray, plane->nvec);
	if (t < record->tmin || record->tmax < t)
		return (false);
	record->t = t;
	record->tmax = t;
	record->p = vplus(camera->point, vmulti_s(ray, t));
	record->nvec = plane->nvec;
	return (true);
}

bool	hit_object(t_camera *camera, t_object *objs, t_vec ray, t_hit *record)
{
	if (objs->type == type_sphere)
		return (hit_sphere(camera, objs, ray, record));
	if (objs->type == type_plane)
		return (hit_plane(camera, objs, ray, record));
	if (objs->type == type_cylinder)
		return (hit_cylinder(camera, objs, ray, record));
	return (false);
}

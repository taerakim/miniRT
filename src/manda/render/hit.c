/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 22:31:04 by yeondcho         ###   ########.fr       */
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
		record->nvec = vmulti_s(record->nvec, -1);
	}
}

bool	hit_cylinder(t_camera *camera, t_object *cylinder, t_vec ray)
{
	if (hit_cylinder_side(camera, cylinder, ray))
	{
		return (true);
	}
	else
	{
		if (hit_cylinder_base(camera, cylinder, ray, -1) \
		|| hit_cylinder_base(camera, cylinder, ray, 1))
		{
			return (true);
		}
	}
	return (false);
}

double	min(double a, double b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (b);
		else
			return (a);
	}
	else if (a > 0)
		return (a);
	else if (b > 0)
		return (b);
	return (0);
}

bool	hit_cylinder_side(t_camera *camera, t_object *cylinder, t_vec ray)
{
	const t_vec		ce = vminus(camera->point \
							, vplus(vmulti_s(cylinder->nvec \
							, -1 * (cylinder->height / 2)), cylinder->point));
	const double	a = pow(vinner(ray, cylinder->nvec), 2) - 1;
	const double	b = vinner(ray, cylinder->nvec) \
						* vinner(ce, cylinder->nvec) - vinner(ce, ray);
	const double	c = pow(cylinder->diameter / 2, 2) - vinner(ce, ce) \
						+ pow(vinner(ce, cylinder->nvec), 2);
	const double	det = b * b - a * c;
	const double	t = min((-b + sqrt(det)) / a, (-b - sqrt(det)) / a);
	const t_vec		cp = vplus(ce, vmulti_s(ray, t));

	if (det < 0 || t < 0)
		return (false);
	if (!(0 <= vinner(cp, cylinder->nvec) && vinner(cp, cylinder->nvec) <= cylinder->height))
		return (false);
	return (true);
}

bool	hit_cylinder_base(t_camera *camera, t_object *cylinder, \
t_vec ray, int dir)
{
	const t_vec		c = vplus(vmulti_s(cylinder->nvec, dir * (cylinder->height / 2)), cylinder->point);
	const t_vec		ec = vminus(c, camera->point);
	const double	t = vinner(ec, cylinder->nvec) / vinner(ray, cylinder->nvec);
	const t_vec		cp = vplus(vminus(camera->point, c), vmulti_s(ray, t));

	if (vinner(cp, cp) <= pow(cylinder->diameter / 2, 2))
		return (true);
	return (false);
}

bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray, t_hit *record)
{
	const double	a = 1;
	const double	b = vinner(ray, vminus(camera->point, sphere->point));
	const double	c = vinner(vminus(camera->point, sphere->point) \
								, vminus(camera->point, sphere->point)) \
						- pow(sphere->diameter / 2, 2);
	const double	det = b * b - a * c;
	double			sqrted;
	double			root;

	if (det < 0)
		return (false);
	sqrted = sqrt(det);
	root = (sqrted - b) / a;
	if (root < record->tmin || record->tmax < root)
	{
		root = (sqrted - b) / a;
		if (root < record->tmin || record->tmax < root)
			return (false);
	}
	record->t = root;
	record->p = vplus(camera->point, vmulti_s(ray, root));
	record->nvec = vdivi_s(vminus(record->p, sphere->point)\
								, sphere->diameter / 2);
	
	_check_front(ray, record);
	return (true);
}

bool	hit_plane(t_object *plane, t_vec ray)
{
	if (vinner(ray, plane->nvec) < 0)
		return (true);
	return (false);
}

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

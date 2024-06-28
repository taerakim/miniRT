/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:02:37 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:33:52 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

bool	hit_cylinder(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record)
{
	bool	ret;

	ret = false;
	if (hit_cylinder_side(camera, cylinder, ray, record))
		ret = true;
	if (hit_cylinder_top(camera, cylinder, ray, record))
		ret = true;
	if (hit_cylinder_base(camera, cylinder, ray, record))
		ret = true;
	return (ret);
}

bool	hit_cylinder_side(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record)
{
	const t_vec	ce = vminus(camera, vplus(vmulti_s(cylinder->nvec \
							, -1 * (cylinder->height / 2)), cylinder->point));
	const t_det	ans = det(pow(vinner(ray, cylinder->nvec), 2) - 1, \
	vinner(ray, cylinder->nvec) * vinner(ce, cylinder->nvec) - vinner(ce, ray), \
	pow(cylinder->diameter / 2, 2) - vinner(ce, ce) \
	+ pow(vinner(ce, cylinder->nvec), 2));
	t_vec		cp;

	if (ans.det < 0)
		return (false);
	cp = vplus(ce, vmulti_s(ray, ans.t));
	if (!(0 <= vinner(cp, cylinder->nvec) \
	&& vinner(cp, cylinder->nvec) <= cylinder->height))
		return (false);
	if (ans.t < record->tmin || record->tmax < ans.t)
		return (false);
	record->t = ans.t;
	record->tmax = record->t;
	record->ishit = true;
	record->p = vplus(camera, vmulti_s(ray, ans.t));
	record->nvec = vunit(vminus(cp, vmulti_s(cylinder->nvec \
											, vinner(cp, cylinder->nvec))));
	record->object = *cylinder;
	return (true);
}

bool	hit_cylinder_top(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record)
{
	const t_vec		c = vplus(vmulti_s(cylinder->nvec, \
	-1 * (cylinder->height / 2)), cylinder->point);
	const t_vec		ec = vminus(c, camera);
	const double	t = vinner(ec, cylinder->nvec) \
	/ vinner(ray, cylinder->nvec);
	const t_vec		cp = vplus(vminus(camera, c), vmulti_s(ray, t));

	if (vinner(cp, cp) > pow(cylinder->diameter / 2, 2))
		return (false);
	if (t < record->tmin || record->tmax < t)
		return (false);
	record->t = t;
	record->tmax = record->t;
	record->ishit = true;
	record->p = vplus(camera, vmulti_s(ray, t));
	record->nvec = cylinder->nvec;
	record->object = *cylinder;
	return (true);
}

bool	hit_cylinder_base(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record)
{
	const t_vec		c = vplus(vmulti_s(cylinder->nvec, \
	1 * (cylinder->height / 2)), cylinder->point);
	const t_vec		ec = vminus(c, camera);
	const double	t = vinner(ec, cylinder->nvec) \
	/ vinner(ray, cylinder->nvec);
	const t_vec		cp = vplus(vminus(camera, c), vmulti_s(ray, t));

	if (vinner(cp, cp) > pow(cylinder->diameter / 2, 2))
		return (false);
	if (t < record->tmin || record->tmax < t)
		return (false);
	record->t = t;
	record->tmax = record->t;
	record->ishit = true;
	record->p = vplus(camera, vmulti_s(ray, t));
	record->nvec = cylinder->nvec;
	record->object = *cylinder;
	return (true);
}

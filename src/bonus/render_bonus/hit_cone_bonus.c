/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 22:25:32 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_bonus.h"
#include "vector_bonus.h"

bool
hit_cone_side(t_point camera, t_object *cone, t_vec ray, t_hit *record);
bool
hit_cone_base(t_point camera, t_object *cone, t_vec ray, t_hit *record);

bool	hit_cone(t_point camera, t_object *cone, t_vec ray, t_hit *record)
{
	bool	ret;

	ret = false;
	if (hit_cone_side(camera, cone, ray, record))
		ret = true;
	if (hit_cone_base(camera, cone, ray, record))
		ret = true;
	return (ret);
}

bool	hit_cone_side(t_point camera, t_object *cone, \
t_vec ray, t_hit *record)
{
	const t_point	c = vplus(cone->point, \
	vmulti_s(vmulti_s(cone->nvec, -1), cone->height));
	const t_vec		ce = vminus(camera, c);
	const double	theta = atan((cone->diameter / 2) / cone->height);
	const t_det		ans = det(pow(vinner(ray, cone->nvec), 2) - \
	pow(cos(theta), 2), vinner(ray, cone->nvec) * vinner(ce, cone->nvec) - \
	vinner(ce, ray) * pow(cos(theta), 2), \
	pow(vinner(ce, cone->nvec), 2) - vinner(ce, ce) * pow(cos(theta), 2));
	t_vec			cp;

	if (ans.det < 0 || ans.t < record->tmin || record->tmax < ans.t)
		return (false);
	cp = vplus(ce, vmulti_s(ray, ans.t));
	if (!(0 <= vinner(cone->nvec, cp) \
	&& vinner(cone->nvec, cp) <= cone->height))
		return (false);
	record->t = ans.t;
	record->tmax = record->t;
	record->ishit = true;
	record->p = vplus(camera, vmulti_s(ray, ans.t));
	record->nvec = vunit(vminus(cp, \
	vmulti_s(cone->nvec, sqrt(vinner(cp, cp)) / cos(theta))));
	record->object = *cone;
	return (true);
}

bool	hit_cone_base(t_point camera, t_object *cone, \
t_vec ray, t_hit *record)
{
	const t_vec	ec = vminus(cone->point, camera);
	double		t;
	t_vec		cp;

	if (vinner(ray, cone->nvec) == 0)
		return (false);
	t = vinner(ec, cone->nvec) / vinner(ray, cone->nvec);
	cp = vplus(vminus(camera, cone->point), \
	vmulti_s(ray, t));
	if (vinner(cp, cp) > pow(cone->diameter / 2, 2))
		return (false);
	if (t < record->tmin || record->tmax < t)
		return (false);
	record->t = t;
	record->tmax = record->t;
	record->ishit = true;
	record->p = vplus(camera, vmulti_s(ray, t));
	record->nvec = cone->nvec;
	record->object = *cone;
	return (true);
}

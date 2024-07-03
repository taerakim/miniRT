/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:31:36 by taerakim          #+#    #+#             */
/*   Updated: 2024/07/03 12:18:51 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

t_vec	get_ray(t_camera *camera, int i, int k)
{
	t_vec	ray;

	ray = vunit(vplus(camera->lefttop, \
			vplus(vmulti_s(camera->dx, i), \
				vmulti_s(camera->dy, k))));
	return (ray);
}

static t_vec	_get_side_vec(t_vec look)
{
	t_vec	cross;

	cross = vcross(vset(0, 1, 0), look);
	if (fabs(cross.x) < EPSILON \
	&& fabs(cross.y) < EPSILON \
	&& fabs(cross.z) < EPSILON)
		return (vcross(vset(0, 0, 1), look));
	return (cross);
}

void	set_viewport(t_camera *camera)
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
	double	gx;
	double	gy;

	w = camera->nvec;
	u = _get_side_vec(w);
	v = vcross(u, w);
	gx = tan(camera->fov / 2 * M_PI / 180) * FOCAL_LENGTH;
	gy = gx * WINDOW_H / WINDOW_W;
	camera->lefttop = vminus(vminus(w, vmulti_s(u, gx)), vmulti_s(v, gy));
	camera->dx = vmulti_s(u, 2 * gx / (WINDOW_W - 1));
	camera->dy = vmulti_s(v, 2 * gy / (WINDOW_H - 1));
}

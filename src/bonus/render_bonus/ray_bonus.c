/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:31:36 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_bonus.h"
#include "vector_bonus.h"

t_vec	get_ray(t_camera *camera, int i, int k)
{
	t_vec	ray;

	ray = vunit(vplus(camera->lefttop, \
			vplus(vmulti_s(camera->dx, i), \
				vmulti_s(camera->dy, k))));
	return (ray);
}

void	set_viewport(t_camera *camera)
{
	t_vec	u;
	t_vec	v;
	t_vec	w;
	double	gx;
	double	gy;

	w = camera->nvec;
	if (vdiff(vset(0, 1, 0), w) == true)
		u = vcross(vset(0, 0, -1), w);
	else
		u = vcross(vset(0, 1, 0), w);
	v = vcross(u, w);
	gx = tan(camera->fov / 2 * M_PI / 180) * FOCAL_LENGTH;
	gy = gx * WINDOW_H / WINDOW_W;
	camera->lefttop = vminus(vminus(w, vmulti_s(u, gx)), vmulti_s(v, gy));
	camera->dx = vmulti_s(u, 2 * gx / (WINDOW_W - 1));
	camera->dy = vmulti_s(v, 2 * gy / (WINDOW_H - 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:31:36 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 16:10:08 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

t_vec	get_ray(t_camera *camera, int i, int k)
{
	t_vec	ray;

	ray = vec_addtion(camera->lefttop \
			, vec_addtion(vec_multi_scala(camera->dx, i)\
						, vec_multi_scala(camera->dy, k)));
	return (ray);
}

// 카메라 축 (u, v, w)
void	set_viewport(t_camera *camera)
{
	t_vec	w;
	t_vec	u;
	t_vec	v;
	double	gx;
	double	gy;

	w = camera->nvec;
	if (vec_diff(w, vec_set(0, -1, 0)) == true)
		u = vec_cross(w, vec_set(0, 0, 1));
	else
		u = vec_cross(w, vec_set(0, -1, 0));
	v = vec_cross(u, w);
	gx = tan(camera->fov / 2 * M_PI / 180);
	gy = gx * WINDOW_H / WINDOW_W;
	camera->lefttop = vec_subtraction(w \
										, vec_addtion(vec_multi_scala(u, gx) \
													, vec_multi_scala(v, gy)));
	camera->dx = vec_multi_scala(u, 2 * gx / (WINDOW_W - 1));
	camera->dy = vec_multi_scala(v, 2 * gy / (WINDOW_H - 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 10:20:44 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rt_struct.h"
#include "vector.h"

bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray)
{
	const double	a = vec_inner(ray, ray);
	const double	b = 2.0 * vec_inner(vec_subtraction(camera->point, sphere->point), ray);
	const double	c = vec_inner(vec_subtraction(camera->point, sphere->point), vec_subtraction(camera->point, sphere->point)) \
						 - sphere->diameter;
	const double	discriminant = b * b - 4 * a * c;

	if (discriminant >= 0)
		return (true);
	return (false);
}

bool	hit_plane(t_object *plane, t_vec ray)
{
	if (vec_inner(ray, plane->nvec) < 0)
		return (true);
	return (false);
}

// 모든 object에 대해 type을 확인하고 각기 실행해주는 함수
bool	hit_object(t_camera *camera, t_object *objs, t_vec ray)
{
	if (objs->type == sphere)
		return (hit_sphere(camera, objs, ray));
	if (objs->type == plane)
		return (hit_plane(objs, ray));
	if (objs->type == cylinder)
		return (false);//함수 생성 해야함
	return (false);
}

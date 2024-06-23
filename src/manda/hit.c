/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 10:20:07 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "rt_struct.h"
#include "vector.h"

//bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray)
//{
//	const discriminant = vec_inner()
//}

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
		return (false);//함수 생성 해야함
	if (objs->type == plane)
		return (hit_plane(objs, ray));
	if (objs->type == cylinder)
		return (false);//함수 생성 해야함
	return (false);
}

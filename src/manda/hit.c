/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:29:47 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:41:22 by taerakim         ###   ########.fr       */
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

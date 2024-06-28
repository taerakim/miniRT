/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:47:29 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:34:17 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

bool	hit_trace(t_object **head, t_hit *hit, t_light *light)
{
	t_hit	record;
	t_vec	lp;
	t_vec	ray;

	hit->p = vplus(hit->p, vmulti_s(hit->nvec, BIAS));
	lp = vminus(hit->p, light->point);
	record.tmin = 1e-6;
	record.tmax = RENDER_MAX;
	record.t = 0;
	record.ishit = false;
	ray = vunit(lp);
	hit_object(light->point, head, ray, &record);
	if (record.ishit && pow(record.tmax, 2) < vinner(lp, lp))
		return (false);
	return (record.ishit);
}

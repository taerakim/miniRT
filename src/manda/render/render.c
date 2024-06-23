/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:35:21 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 17:16:56 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"

unsigned long	rgb_to_hex(t_color color)
{
	const int	r = round(color.x);
	const int	g = round(color.y);
	const int	b = round(color.z);

	return ((r << 16) | (g << 8) | b);
}

void	render_process(t_element *element, t_mlx *env, t_vec ray, int i, int k)
{
	t_object	*object;
	t_hit		record;
	t_color		color;

	record.tmin = 0;
	record.tmax = RENDER_MAX;
	object = element->objs;
	while(object)
	{
		if (hit_object(&element->camera, object, ray, &record) == true)
		{
			color = vmulti_s(vplus(object->rgb, element->ambient.rgb), element->ambient.ratio);
			put_pixel(&env->img, i, k, rgb_to_hex(color));
		}
		object = object->next;
	}
}

void	render(t_element *element, t_mlx *env)
{
	int		i;
	int		k;
	t_vec	ray;
	t_hit	record;

	record.tmin = 0;
	record.tmax = RENDER_MAX;

	k = 0;
	while (k < WINDOW_H)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			ray = get_ray(&element->camera, i, k);
			render_process(element, env, ray, i, k);
			i++;
		}
		k++;
	}
}

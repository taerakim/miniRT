/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:35:21 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 15:59:52 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_bonus.h"
#include "vector_bonus.h"
#include "libft.h"

unsigned int	rgb_to_hex(t_color color)
{
	const int	r = round(color.x);
	const int	g = round(color.y);
	const int	b = round(color.z);

	return ((r << 16) | (g << 8) | b);
}

void	init_record(t_hit *record)
{
	record->ishit = false;
	record->object.rgb = vset(0, 0, 0);
	record->t = 0;
	record->nvec = vset(0, 0, 0);
	record->p = vset(0, 0, 0);
	record->tmin = EPSILON;
	record->tmax = RENDER_MAX;
}

t_color	phong(t_point camera_point, t_hit record, t_light *light, t_color color)
{
	color = cplus(color, \
	diffuse(&record, light, record.object.rgb));
	color = cplus(color, \
	specular(&record, light, record.object.rgb, \
	vunit(vminus(camera_point, record.p))));
	return (color);
}

t_color	get_hit_color(t_element *element, t_vec ray)
{
	t_light		*light;
	t_color		color;
	t_hit		record;

	light = element->light;
	ft_memset(&color, 0, sizeof(t_color));
	init_record(&record);
	if (hit_object(element->camera.point, &element->objs, ray, &record))
	{
		record.object.rgb = cdiv(record.object.rgb, 255);
		_check_front(ray, &record);
		color = cplus(color, ambient(element, record.object.rgb));
		while (light)
		{
			if (hit_trace(&element->objs, &record, light))
				color = phong(element->camera.point, record, light, color);
			light = light->next;
		}
	}
	return (color);
}

void	render(t_element *element, t_mlx *env)
{
	t_vec	ray;
	t_color	color;
	int		i;
	int		k;

	k = 0;
	while (k < WINDOW_H)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			ray = get_ray(&element->camera, i, k);
			color = cmulti_s(get_hit_color(element, ray), 255);
			put_pixel(&env->img, i, k, rgb_to_hex(color));
			i++;
		}
		k++;
	}
}

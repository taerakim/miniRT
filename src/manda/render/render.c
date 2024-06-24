/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:35:21 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/24 20:19:58 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"
#include "libft.h"

unsigned int	rgb_to_hex(t_color color)
{
	const int	r = round(color.x);
	const int	g = round(color.y);
	const int	b = round(color.z);

	return ((r << 16) | (g << 8) | b);
}

t_color	phong_lighting(t_element *element, t_hit *hit, t_color color)
{
	const t_vec		light = vunit(vminus(element->light.point, hit->p));
	const double	kd = fmax(vinner(hit->nvec, light), 0.0) * element->light.ratio;
	const t_color	diffuse = vmulti_s(vset(255,255,255), kd);
	//const t_color	diffuse = vmulti_s(element->light.rgb, kd);
	//light rgb 파싱 필요!

	return (vplus(color, diffuse));
}

t_color	get_hit_color(t_element *element, t_vec ray, t_hit *record)
{
	t_object	*object;
	t_color		color;

	ft_memset(&color, 0, sizeof(t_color));
	record->ishit = false;
	record->tmin = 0;
	record->tmax = RENDER_MAX;
	object = element->objs;
	while (object)
	{
		if (hit_object(&element->camera, object, ray, record) == true)
		{
			record->ishit = true;
			color = vmulti_s(vplus(object->rgb, element->ambient.rgb), element->ambient.ratio);
		}
		object = object->next;
	}
	return (color);
}

void	render(t_element *element, t_mlx *env)
{
	t_vec	ray;
	t_hit	record;
	t_color	color;
	int		i;
	int		k;

	record.tmin = 0;
	record.tmax = RENDER_MAX;
	k = 0;
	while (k < WINDOW_H)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			ray = get_ray(&element->camera, i, k);
			color = get_hit_color(element, ray, &record);
			if (record.ishit == true)
				color = phong_lighting(element, &record, color);
			put_pixel(&env->img, i, k, rgb_to_hex(color));
			i++;
		}
		k++;
	}
}

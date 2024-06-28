/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 16:24:13 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/27 15:28:27 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"
#include "libft.h"

t_color	ambient(t_element *element, t_color obj_color)
{
	return (cmulti(cmulti_s(cdiv(element->ambient.rgb, 255), \
	element->ambient.ratio), obj_color));
}

t_color	diffuse(t_hit *hit, t_light *light, t_color obj_color)
{
	double	ctheta;
	t_vec	l;
	t_color	color;

	color = vset(0, 0, 0);
	l = vunit(vminus(light->point, hit->p));
	ctheta = fmax(vinner(hit->nvec, l), 0);
	color = cplus(color, cmulti_s(cmulti_s(cmulti(obj_color, \
	cdiv(light->rgb, 255)), light->ratio), ctheta));
	return (color);
}

t_color	specular(t_hit *hit, t_light *light, t_color obj_color, t_vec ray)
{
	t_color	color;
	t_vec	l;
	t_vec	r;

	color = vset(0, 0, 0);
	l = vunit(vminus(hit->p, light->point));
	r = vunit(vminus(l, vmulti_s(hit->nvec, 2 * vinner(l, hit->nvec))));
	color = cplus(color, cmulti_s(cmulti_s(cmulti(obj_color, \
	cdiv(light->rgb, 255)), light->ratio), pow(fmax(vinner(r, ray), 0), 30)));
	return (color);
}

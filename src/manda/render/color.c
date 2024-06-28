/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 20:00:40 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/25 21:09:06 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt.h"
#include "vector.h"
#include "libft.h"

t_color	cplus(t_color a, t_color b)
{
	a.x = fmin(a.x + b.x, 255);
	a.y = fmin(a.y + b.y, 255);
	a.z = fmin(a.z + b.z, 255);
	return (a);
}

t_color	cmulti(t_color a, t_color b)
{
	a.x = fmin(a.x * b.x, 255);
	a.y = fmin(a.y * b.y, 255);
	a.z = fmin(a.z * b.z, 255);
	return (a);
}

t_color	cmulti_s(t_color a, double b)
{
	a.x = fmin(a.x * b, 255);
	a.y = fmin(a.y * b, 255);
	a.z = fmin(a.z * b, 255);
	return (a);
}

t_color	cminus(t_color a, t_color b)
{
	a.x = fmax(a.x - b.x, 0);
	a.y = fmax(a.y - b.y, 0);
	a.z = fmax(a.z - b.z, 0);
	return (a);
}

t_color	cdiv(t_color a, double b)
{
	a.x /= b;
	a.y /= b;
	a.z /= b;
	return (a);
}

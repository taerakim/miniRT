/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:14:26 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:29:17 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "ft_error.h"

t_vec	vec_addtion(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec	vec_subtraction(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

t_vec	vec_divi(t_vec a, t_vec b)
{
	t_vec	divi;

	if (b.x == 0 || b.y == 0 || b.z == 0)
		ft_error(error_divider_is_zero);
	divi.x = a.x / b.x;
	divi.y = a.y / b.y;
	divi.z = a.z / b.z;
	return (divi);
}

double	vec_inner(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	cross;

	cross.x = a.y * b.z - a.z * b.y;
	cross.y = a.z * b.x - a.x * b.z;
	cross.z = a.x * b.y - a.y * b.x;
	return (cross);
}

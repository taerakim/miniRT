/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:13:54 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:59:15 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdbool.h>
#include "rt_struct.h"
#include "ft_error.h"

t_vec	vec_set(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vec_get(t_point a, t_point b)
{
	t_vec	vec;

	vec.x = a.x - b.x;
	vec.y = a.y - b.y;
	vec.z = a.z - b.z;
	return (vec);
}

t_vec	vec_unit(t_vec vec)
{
	const double	length = sqrt(vec.x * vec.x \
								+ vec.y * vec.y + vec.z * vec.z);

	if (length == 0)
		ft_error(error_divider_is_zero);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

bool	vec_diff(t_vec a, t_vec b)
{
	bool	result;

	result = true;
	if (a.x != b.x)
		result = false;
	if (a.y != b.y)
		result = false;
	if (a.z != b.z)
		result = false;
	return (result);
}

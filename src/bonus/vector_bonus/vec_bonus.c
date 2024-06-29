/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:13:54 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 15:00:51 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_struct_bonus.h"
#include "ft_error_bonus.h"

t_vec	vset(double x, double y, double z)
{
	t_vec	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

t_vec	vunit(t_vec vec)
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

bool	vdiff(t_vec a, t_vec b)
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

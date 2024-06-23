/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:14:50 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 17:12:26 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "ft_error.h"

t_vec	vplus_s(t_vec vec, double scala)
{
	vec.x += scala;
	vec.y += scala;
	vec.z += scala;
	return (vec);
}

t_vec	vminus_s(t_vec vec, double scala)
{
	vec.x -= scala;
	vec.y -= scala;
	vec.z -= scala;
	return (vec);
}

t_vec	vmulti_s(t_vec vec, double scala)
{
	vec.x *= scala;
	vec.y *= scala;
	vec.z *= scala;
	return (vec);
}

t_vec	vdivi_s(t_vec vec, double scala)
{
	if (scala == 0)
		ft_error(error_divider_is_zero);
	vec.x /= scala;
	vec.y /= scala;
	vec.z /= scala;
	return (vec);
}

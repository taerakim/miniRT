/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal_scala.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:14:50 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:28:15 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_struct.h"
#include "ft_error.h"

t_vec	vec_addtion_scala(t_vec vec, double scala)
{
	vec.x += scala;
	vec.y += scala;
	vec.z += scala;
	return (vec);
}

t_vec	vec_subtraction_scala(t_vec vec, double scala)
{
	vec.x -= scala;
	vec.y -= scala;
	vec.z -= scala;
	return (vec);
}

t_vec	vec_multi_scala(t_vec vec, double scala)
{
	vec.x *= scala;
	vec.y *= scala;
	vec.z *= scala;
	return (vec);
}

t_vec	vec_divi_scala(t_vec vec, double scala)
{
	if (scala == 0)
		ft_error(error_divider_is_zero);
	vec.x /= scala;
	vec.y /= scala;
	vec.z /= scala;
	return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:05 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "minirt_bonus.h"

double	min(double a, double b)
{
	if (a > 0 && b > 0)
	{
		if (a > b)
			return (b);
		else
			return (a);
	}
	else if (a > 0)
		return (a);
	else if (b > 0)
		return (b);
	return (0);
}

t_det	det(double a, double b, double c)
{
	t_det	result;

	result.det = b * b - a * c;
	result.t = min((-b + sqrt(result.det)) / a, (-b - sqrt(result.det)) / a);
	return (result);
}

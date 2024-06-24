/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 11:09:05 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/24 17:08:22 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "rt_struct.h"
#include "minirt.h"

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
	return (-1);
}

t_det	det(double a, double b, double c)
{
	t_det	result;

	result.det = b * b - a * c;
	result.t = min((-b + sqrt(result.det)) / a, (-b - sqrt(result.det)) / a);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:45:03 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/23 17:10:08 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <float.h>
#include "parse.h"
#include "ft_error.h"

static int	_handle_prev(char *str, double *result, int *sign)
{
	int	idx;

	*result = 0.0;
	*sign = 1;
	idx = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
		*sign = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	return (idx);
}

int	atod(char *str, double *result)
{
	double	fraction;
	int		sign;
	int		idx;

	if (str == NULL)
		return (0);
	idx = _handle_prev(str, result, &sign);
	fraction = 0.1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		//if (*result > (DBL_MAX - (str[idx] - '0')) / 10)
			//return (_error_atod(result));
		*result = *result * 10.0 + (str[idx] - '0');
		idx++;
	}
	if (str[idx] == '.')
		idx += 1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		//if (*result > DBL_MAX - (str[idx] - '0') * fraction)
		//	return (_error_atod(result));
		*result += (str[idx] - '0') * fraction;
		fraction *= 0.1;
		idx++;
	}
	*result *= sign;
	if (str[idx] != '\0')
		ft_error(error_init);
	return (1);
}

#include<stdio.h>
void	print_element(t_element *elem)
{
	t_object	*ptr;
	int			i;

	printf("element print==========================================================\n");
	printf("CAMERA(t_camera): \n\t point: %.2f, %.2f, %.2f \n\t nvec: %.2f, %.2f, %.2f \n\t fov: %f\n\n", \
	elem->camera.point.x, elem->camera.point.y, elem->camera.point.z, \
	elem->camera.nvec.x, elem->camera.nvec.y, elem->camera.nvec.z, \
	elem->camera.fov);
	printf("AMBIENT(t_ambient): \n\t rgb: %.2f, %.2f, %.2f \n\t ratio: %.2f\n\n", \
	elem->ambient.rgb.x, elem->ambient.rgb.y, elem->ambient.rgb.z, elem->ambient.ratio);
	printf("LIGHT(t_light): \n\t point: %.2f, %.2f, %.2f \n\t ratio: %.2f\n", \
	elem->light.point.x, elem->light.point.y, elem->light.point.z, elem->light.ratio);
	printf("=======================================================================\n");
	printf("Objects list\n ");
	ptr = elem->objs;
	i = 1;
	while (ptr)
	{
		if (ptr->type == type_cylinder)
		{
			printf("\tOBJECT(#%d): cylinder -> \n\t\t point: %.2f, %.2f, %.2f \n\t\t nvec: %.2f, %.2f, %.2f \n\t\t diameter: %.2f \n\t\t height: %.2f \n\t\t rgb: %.2f, %.2f, %.2f \n\n", i,\
			ptr->point.x, ptr->point.y, ptr->point.z, \
			ptr->nvec.x, ptr->nvec.y, ptr->nvec.z, ptr->diameter, ptr->height, 
			ptr->rgb.x, ptr->rgb.y, ptr->rgb.z);
		}
		if (ptr->type == type_plane)
		{
			printf("\tOBJECT(#%d): plane -> \n\t\t point: %.2f, %.2f, %.2f \n\t\t nvec: %.2f, %.2f, %.2f \n\t\t rgb: %.2f, %.2f, %.2f \n\n", i,\
			ptr->point.x, ptr->point.y, ptr->point.z, \
			ptr->nvec.x, ptr->nvec.y, ptr->nvec.z, \
			ptr->rgb.x, ptr->rgb.y, ptr->rgb.z);
		}
		if (ptr->type == type_sphere)
		{
			printf("\tOBJECT(#%d): sphere -> \n\t\t point: %.2f, %.2f, %.2f \n\t\t diameter: %.2f \n\t\t rgb: %.2f, %.2f, %.2f \n\n", i,\
			ptr->point.x, ptr->point.y, ptr->point.z, ptr->diameter, \
			ptr->rgb.x, ptr->rgb.y, ptr->rgb.z);
		}
		ptr = ptr->next;
		i++;
	}
	printf("=======================================================================\n");
}

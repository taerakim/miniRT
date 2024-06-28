/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:11:09 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:23:09 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
#include "ft_error.h"
#include "vector.h"

t_vec	vec(char *vec)
{
	t_vec	obj;
	char	**val;

	val = ft_split(vec, ',');
	if (arg_len(val) != 3)
		ft_error(error_file_format);
	atod(val[0], &obj.x);
	atod(val[1], &obj.y);
	atod(val[2], &obj.z);
	ft_clear_char(val);
	return (vunit(obj));
}

t_point	point(char *pos)
{
	t_point	obj;
	char	**point;

	point = ft_split(pos, ',');
	if (arg_len(point) != 3)
		ft_error(error_file_format);
	atod(point[0], &obj.x);
	atod(point[1], &obj.y);
	atod(point[2], &obj.z);
	ft_clear_char(point);
	return (obj);
}

t_color	color(char *rgb)
{
	t_color	obj;
	char	**color;

	color = ft_split(rgb, ',');
	if (arg_len(color) != 3)
		ft_error(error_file_format);
	atod(color[0], &obj.x);
	atod(color[1], &obj.y);
	atod(color[2], &obj.z);
	ft_clear_char(color);
	return (obj);
}

int	arg_len(char **vals)
{
	int	i;

	if (vals == NULL)
		return (0);
	i = 0;
	while (vals[i])
		i++;
	return (i);
}

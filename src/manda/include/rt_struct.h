/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/19 15:55:25 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef struct s_color
{
	double	r;
	double	g;
	double	b;
}	t_color;

typedef enum e_obj_type
{
	sphere,
	plane,
	cylinder
}	t_obj_type;

typedef struct s_object
{
	t_obj_type	type;
	t_point		point;
	t_vec		nvec;
	t_color		rgb;
	double		ratio;
	double		diameter;
	double		height;
	void		*next;
}	t_object;

typedef struct s_camera
{
	t_point	point;
	t_vec	nvec;
	int		fov;
}	t_camera;

typedef struct s_ambient
{
	t_color	rgb;
	double	ratio;
}	t_ambient;

typedef struct s_light
{
	t_point	point;
	double	ratio;
}	t_light;

typedef struct s_element
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		light;
	t_object	*objs;
}	t_element;

#endif
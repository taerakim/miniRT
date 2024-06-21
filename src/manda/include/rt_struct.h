/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/21 15:34:21 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	t_point		pos;
	t_vec		nvec;
	t_color		rgb;
	double		ratio;
	double		diameter;
	double		height;
	void		*next;
}	t_object;

typedef struct s_camera
{
	t_point	pos;
	t_vec	nvec;
	int		fov;
	/* for VIEWPORT*/
	t_vec	lefttop;
	t_vec	dx;
	t_vec	dy;
}	t_camera;

typedef struct s_ambient
{
	t_color	rgb;
	double	ratio;
}	t_ambient;

typedef struct s_light
{
	t_point	pos;
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
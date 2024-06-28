/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:52:27 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

/* ________________________________ INCLUDE _________________________________ */
# include <stdbool.h>

/* ________________________________ TYPEDEF _________________________________ */
typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;
typedef struct s_vec	t_color;

/* ________________________________ STRUCTS _________________________________ */
struct s_vec
{
	double	x;
	double	y;
	double	z;
};

typedef enum e_obj_type
{
	type_sphere,
	type_plane,
	type_cylinder,
	type_cone,
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
	double	fov;
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
	t_point	point;
	double	ratio;
	t_color	rgb;
	void	*next;
}	t_light;

typedef struct s_element
{
	t_camera	camera;
	t_ambient	ambient;
	t_light		*light;
	t_object	*objs;
}	t_element;

typedef struct s_hit
{
	bool		ishit;
	t_vec		nvec;
	t_object	object;
	t_point		p;
	double		t;
	double		tmin;
	double		tmax;
	bool		isfront;
}	t_hit;

typedef struct s_det
{
	double	det;
	double	t;
}	t_det;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_struct.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 14:07:28 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/23 16:40:13 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_STRUCT_H
# define RT_STRUCT_H

# include <stdbool.h>

typedef struct s_vec	t_vec;
typedef struct s_vec	t_point;
typedef struct s_vec	t_color;

struct s_vec
{
	double	x;
	double	y;
	double	z;
};

//typedef struct s_color
//{
//	double	x;//r
//	double	y;//g
//	double	z;//b
//}	t_color;

typedef enum e_obj_type
{
	type_sphere,
	type_plane,
	type_cylinder
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

typedef struct s_hit
{
	t_vec	nvec;
	t_point	p;
	double	t;
	double	tmin;
	double	tmax;
	bool	isfront;
}	t_hit;

#endif
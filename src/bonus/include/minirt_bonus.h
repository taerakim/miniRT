/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:33:38 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

/* ________________________________ INCLUDE _________________________________ */
# include "rt_struct_bonus.h"

/* _________________________________ DEFINE _________________________________ */
/* WINDOW */
# define WINDOW_W 1920
# define WINDOW_H 1080
# define PROGRAM "miniRT"

/* RAYTRACING */
# define FOCAL_LENGTH 1
# define VIEWPORT_HEIGHT 1.0
# define RENDER_MAX 10000
# define EPSILON 1e-6
# define BIAS 1e-5

/* MLX */
# define NOT_USE -1
# define KEY_PRESS 2
# define KEY_ESC 53
# define CROSS_BUTTON 17

/* _________________________________ STRUCT _________________________________ */
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		img;
}	t_mlx;

/* ________________________________ FUNCTION ________________________________ */
/* init.c */
void	init_file(t_element *element, char *file);
void	set_mlx_init(t_mlx *env);
void	set_viewport(t_camera *camera);
/* mlx.c */
void	put_pixel(t_img *img, int x, int y, int color);
int		key_press(int keycode, void *arg);
int		exit_success(void *arg);

/* render.c */
void	render(t_element *element, t_mlx *env);
/* ray.c */
t_vec	get_ray(t_camera *camera, int i, int k);

/* hit.c */
bool	hit_object(t_point origin, t_object **objs, t_vec ray, t_hit *record);
bool	hit_sphere(t_point camera, t_object *sphere, t_vec ray, t_hit *record);
bool	hit_plane(t_point camera, t_object *plane, t_vec ray, t_hit *record);
/* hit_cylinder.c */
bool	\
hit_cylinder(t_point camera, t_object *cylinder, t_vec ray, t_hit *record);
bool	\
hit_cylinder_side(t_point camera, t_object *cylinder, t_vec ray, t_hit *record);
bool	hit_cylinder_base(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record);
bool	hit_cylinder_top(t_point camera, t_object *cylinder, \
t_vec ray, t_hit *record);
/* hit_trace.c */
bool	hit_trace(t_object **head, t_hit *hit, t_light *light);
/* hit_cone.c*/
bool	hit_cone(t_point camera, t_object *cone, t_vec ray, t_hit *record);

void	_check_front(t_vec ray, t_hit *record);
/* calc.c */
double	min(double a, double b);
t_det	det(double a, double b, double c);
t_color	cmulti(t_color a, t_color b);

/* lighting.c */
t_color	ambient(t_element *element, t_color obj_color);
t_color	diffuse(t_hit *hit, t_light *light, t_color obj_color);
t_color	specular(t_hit *hit, t_light *light, t_color obj_color, t_vec ray);

/* color.c */
t_color	cplus(t_color a, t_color b);
t_color	cmulti(t_color a, t_color b);
t_color	cmulti_s(t_color a, double b);
t_color	cminus(t_color a, t_color b);
t_color	cdiv(t_color a, double b);

#endif
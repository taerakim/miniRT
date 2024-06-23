/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:33:38 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 16:35:36 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ________________________________ INCLUDE _________________________________ */
# include <stdbool.h>
# include "rt_struct.h"

// __ DELETE 예정 __
#include<stdio.h>
#include<unistd.h>
// __ DELETE 예정 __

/* _________________________________ DEFINE _________________________________ */
# define WINDOW_W 500
# define WINDOW_H 300
# define PROGRAM "miniRT"

# define FOCAL_LENGTH 1.0
# define VIEWPORT_HEIGHT 2.0
# define RENDER_MAX 100000000//??????

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
bool	hit_object(t_camera *camera, t_object *objs, t_vec ray, t_hit *record);
bool	hit_sphere(t_camera *camera, t_object *sphere, t_vec ray, t_hit *record);
bool	hit_plane(t_object *plane, t_vec ray);
bool	hit_cylinder(t_camera *camera, t_object *cylinder, t_vec ray);

#endif
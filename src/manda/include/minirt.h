/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:33:38 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 16:09:04 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

/* ________________________________ INCLUDE _________________________________ */
# include <stdbool.h>
# include "rt_struct.h"

// __ DELETE 예정 __
#include<stdio.h>
// __ DELETE 예정 __

/* _________________________________ DEFINE _________________________________ */
# define WINDOW_W 500
# define WINDOW_H 300
# define PROGRAM "miniRT"

# define FOCAL_LENGTH 1.0
# define VIEWPORT_HEIGHT 2.0

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
void	set_mlx_init(t_mlx *env);
void	set_viewport(t_camera *camera);
/* mlx.c */
void	put_pixel(t_img *img, int x, int y, int color);
int		key_press(int keycode, void *arg);
int		exit_success(void *arg);
/* ray.c */
t_vec	get_ray(t_camera *camera, int i, int k);
/* hit.c */
//sphere
bool	hit_plane(t_object *plane, t_vec ray);
//cylinder

#endif
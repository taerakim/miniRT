/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:24:46 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 16:04:24 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"

// __ DELETE 예정 __
#include"libft.h"
// __ DELETE 예정 __

int	main(int ac, char **av)
{
	t_mlx		env;
	t_element	element;

	//if (ac != 2)
	//	return (-1);
	(void)av;
	(void)ac;
	//init_file(&element, av[1]);
	/* ________________________________ TEST_SET ____________________________ */
	element.camera.fov = 60;
	element.camera.point.x = 0;
	element.camera.point.y = 0;
	element.camera.point.z = 100;
	element.camera.nvec.x = 0;
	element.camera.nvec.y = 0;
	element.camera.nvec.z = -1;
	element.ambient.rgb.x = 255;
	element.ambient.rgb.y = 255;
	element.ambient.rgb.z = 255;
	element.ambient.ratio = 0.1;
	element.objs = (t_object *)ft_calloc(sizeof(t_object), 1);
	element.objs->type = type_plane;
	element.objs->rgb.x = 0;
	element.objs->rgb.y = 0;
	element.objs->rgb.z = 255;
	element.objs->point.x = 0;
	element.objs->point.y = -10;
	element.objs->point.z = 0;
	element.objs->nvec.x = 0;
	element.objs->nvec.y = 1;
	element.objs->nvec.z = 0;
	element.objs->next = (t_object *)ft_calloc(sizeof(t_object), 1);
	t_object *more = element.objs->next;
	//more->type = type_sphere;
	//more->diameter = 100;
	//more->rgb.x = 0;
	//more->rgb.y = 255;
	//more->rgb.z = 0;
	//more->point.x = 0;
	//more->point.y = 0;
	//more->point.z = 0;
	more->type = type_cylinder;
	more->diameter = 100;
	more->rgb.x = 255;
	more->rgb.y = 0;
	more->rgb.z = 0;
	more->point.x = 0;
	more->point.y = 0;
	more->point.z = 0;
	more->nvec.x = 0;
	more->nvec.y = 1;
	more->nvec.z = 0;
	//more->type = plane;
	//more->rgb.x = 255;
	//more->rgb.y = 255;
	//more->rgb.z = 255;
	//more->point.x = 0;
	//more->point.y = 0;
	//more->point.z = -10;
	//more->nvec.x = 0;
	//more->nvec.y = 0;
	//more->nvec.z = 1;
	/* ______________________________________________________________________ */
	set_mlx_init(&env);
	set_viewport(&element.camera);
	render(&element, &env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_hook(env.win, KEY_PRESS, NOT_USE, key_press, &env);
	mlx_hook(env.win, CROSS_BUTTON, NOT_USE, exit_success, NULL);
	mlx_loop(env.mlx);
}

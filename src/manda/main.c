/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:24:46 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 16:10:25 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "minirt.h"
#include "vector.h"

// __ DELETE 예정 __
#include"libft.h"
// __ DELETE 예정 __

int	main(int ac, char **av)
{
	t_mlx		env;
	t_element	element;

	(void)ac;
	(void)av;
	//if (ac != 2)
	//	return (-1);
	set_mlx_init(&env);
/* ________________________________ TEST_SET ________________________________ */
	element.camera.fov = 60;
	element.camera.pos.x = 0;
	element.camera.pos.y = 0;
	element.camera.pos.z = 100;
	element.camera.nvec.x = 0;
	element.camera.nvec.y = 0;
	element.camera.nvec.z = -1;
	element.objs = (t_object *)ft_calloc(sizeof(t_object), 1);
	//element.objs->type = sphere;
	//element.objs->diameter = 10;
	//element.objs->rgb.r = 255;
	//element.objs->rgb.g = 255;
	//element.objs->rgb.b = 255;
	//element.objs->pos.x = 0;
	//element.objs->pos.y = 0;
	//element.objs->pos.z = 0;
	element.objs->type = plane;
	element.objs->rgb.r = 255;
	element.objs->rgb.g = 255;
	element.objs->rgb.b = 255;
	element.objs->pos.x = 0;
	element.objs->pos.y = -10;
	element.objs->pos.z = 0;
	element.objs->nvec.x = 0;
	element.objs->nvec.y = 1;
	element.objs->nvec.z = 0;
/* __________________________________________________________________________ */

	int		i;
	int		k;
	t_vec	ray;

	set_viewport(&element.camera);
	k = 0;
	while (k < WINDOW_H)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			ray = get_ray(&element.camera, i, k);
			if (hit_plane(element.objs, ray) == true)
				put_pixel(&env.img, i, k, 0X000000FF);//BLUE
			else
				put_pixel(&env.img, i, k, 0X00555555);//GREY
			//컬러? 빛? 암튼 계산
			i++;
		}
		k++;
	}
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_hook(env.win, KEY_PRESS, NOT_USE, key_press, &env);
	mlx_hook(env.win, CROSS_BUTTON, NOT_USE, exit_success, NULL);
	mlx_loop(env.mlx);
}

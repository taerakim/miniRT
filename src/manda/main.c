/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:24:46 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/27 22:03:07 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <unistd.h>
#include "minirt.h"
#include "ft_error.h"

int	main(int ac, char **av)
{
	t_mlx		env;
	t_element	element;

	if (ac != 2)
		ft_error(error_argument);
	init_file(&element, av[1]);
	set_mlx_init(&env);
	set_viewport(&element.camera);
	render(&element, &env);
	mlx_put_image_to_window(env.mlx, env.win, env.img.img, 0, 0);
	mlx_hook(env.win, KEY_PRESS, NOT_USE, key_press, &env);
	mlx_hook(env.win, CROSS_BUTTON, NOT_USE, exit_success, NULL);
	mlx_loop(env.mlx);
}

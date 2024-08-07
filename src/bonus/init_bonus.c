/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 17:39:09 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fcntl.h>
#include "minirt_bonus.h"
#include "parse_bonus.h"
#include "ft_error_bonus.h"

void	set_mlx_init(t_mlx *env)
{
	env->mlx = mlx_init();
	if (env->mlx == NULL)
		ft_error(error_mlx_mlx);
	env->win = mlx_new_window(env->mlx, WINDOW_W, WINDOW_H, PROGRAM);
	if (env->win == NULL)
		ft_error(error_mlx_win);
	env->img.img = mlx_new_image(env->mlx, WINDOW_W, WINDOW_H);
	if (env->win == NULL)
		ft_error(error_mlx_img);
	env->img.addr = mlx_get_data_addr(env->img.img, &env->img.bits_per_pixel, \
									&env->img.line_length, &env->img.endian);
}

void	init_file(t_element *element, char *file)
{
	int	fd;

	fd = open(file, O_RDWR);
	if (fd == -1)
		ft_error(error_file);
	if (ft_strncmp(&file[ft_strlen(file) - 3], ".rt", 4) != 0)
		ft_error(error_file_format);
	*element = ft_parse_rt(fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:18:41 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/24 13:21:41 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "minirt.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x <= 0 || x >= WINDOW_W || y <= 0 || y >= WINDOW_H)
		return ;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	key_press(int keycode, void *arg)
{
	if (keycode == KEY_ESC)
		exit_success(NULL);
	(void)arg;
	return (0);
}

int	exit_success(void *arg)
{
	(void)arg;
	exit(0);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:16:58 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/27 22:22:30 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ft_error.h"
#include "libft.h"

void	ft_error(t_error_type errcase)
{
	ft_putendl_fd("Error", 2);
	if (errcase == error_systemcall || errcase == error_file)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (errcase == error_file_format)
		ft_putendl_fd("error: invalid file format", 2);
	else if (errcase == error_argument)
		ft_putendl_fd("error: need .rt file", 2);
	else if (errcase == error_mlx_mlx)
		ft_putendl_fd("error: mlx_init() Failed", 2);
	else if (errcase == error_mlx_win)
		ft_putendl_fd("error: mlx_new_window() Failed", 2);
	else if (errcase == error_mlx_img)
		ft_putendl_fd("error: mlx_new_image() Failed", 2);
	else if (errcase == error_divider_is_zero)
		ft_putendl_fd("error: Devider is zero", 2);
	exit(EXIT_FAILURE);
}

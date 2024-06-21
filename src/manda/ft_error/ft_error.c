/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 00:16:58 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:40:27 by taerakim         ###   ########.fr       */
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
	if (errcase == error_systemcall)
	{
		ft_putstr_fd("\t", 2);
		perror("error");
		exit(EXIT_FAILURE);
	}
	else if (errcase == error_mlx_mlx)
		ft_putendl_fd("\terror: mlx_init() Failed", 2);
	else if (errcase == error_mlx_win)
		ft_putendl_fd("\terror: mlx_new_window() Failed", 2);
	else if (errcase == error_mlx_img)
		ft_putendl_fd("\terror: mlx_new_image() Failed", 2);
	else if (errcase == error_divider_is_zero)
		ft_putendl_fd("\terror: Devider is zero", 2);
	exit(EXIT_FAILURE);
}

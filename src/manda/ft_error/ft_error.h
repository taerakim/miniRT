/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:43 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/27 22:22:47 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

/* ________________________________ INCLUDE _________________________________ */
# include <errno.h>

/* _______________________________ ERROR_TYPE _______________________________ */
typedef enum e_error_type
{
	error_systemcall = -127,
	error_argument,
	error_file,
	error_file_format,
	error_init,
	error_mlx_mlx,
	error_mlx_win,
	error_mlx_img,
	error_divider_is_zero
}	t_error_type;

/* ________________________________ FUNCTION ________________________________ */
void	ft_error(t_error_type errcase);

#endif
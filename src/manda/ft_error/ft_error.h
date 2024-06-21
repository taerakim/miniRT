/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:22:43 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:27:17 by taerakim         ###   ########.fr       */
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
	error_mlx_mlx,
	error_mlx_win,
	error_mlx_img,
	error_divider_is_zero
}	t_error_type;

/* ________________________________ FUNCTION ________________________________ */
void	ft_error(t_error_type errcase);

#endif
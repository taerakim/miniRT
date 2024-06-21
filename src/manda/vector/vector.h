/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:53 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 15:59:27 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "rt_struct.h"

t_vec	vec_set(double x, double y, double z);
t_vec	vec_get(t_point a, t_point b);
t_vec	vec_unit(t_vec vec);
bool	vec_diff(t_vec a, t_vec b);

t_vec	vec_addtion(t_vec a, t_vec b);
t_vec	vec_subtraction(t_vec a, t_vec b);
t_vec	vec_divi(t_vec a, t_vec b);
double	vec_inner(t_vec a, t_vec b);
t_vec	vec_cross(t_vec a, t_vec b);

t_vec	vec_addtion_scala(t_vec vec, double scala);
t_vec	vec_subtraction_scala(t_vec vec, double scala);
t_vec	vec_multi_scala(t_vec vec, double scala);
t_vec	vec_divi_scala(t_vec vec, double scala);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:53 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

/* ________________________________ INCLUDE _________________________________ */
# include "rt_struct_bonus.h"

/* ________________________________ FUNCTION ________________________________ */
t_vec	vset(double x, double y, double z);
t_vec	vunit(t_vec vec);
bool	vdiff(t_vec a, t_vec b);

t_vec	vplus(t_vec a, t_vec b);
t_vec	vminus(t_vec a, t_vec b);
t_vec	vdivi(t_vec a, t_vec b);
double	vinner(t_vec a, t_vec b);
t_vec	vcross(t_vec a, t_vec b);

t_vec	vplus_s(t_vec vec, double scala);
t_vec	vminus_s(t_vec vec, double scala);
t_vec	vmulti_s(t_vec vec, double scala);
t_vec	vdivi_s(t_vec vec, double scala);

#endif
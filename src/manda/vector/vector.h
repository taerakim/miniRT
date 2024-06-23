/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 12:11:53 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/23 17:16:56 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# include "rt_struct.h"

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
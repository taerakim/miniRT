/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/29 14:38:13 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

/* ________________________________ INCLUDE _________________________________ */
# include "rt_struct.h"
# include "libft.h"

/* _________________________________ DEFINE _________________________________ */
# define INIT_AMB 0
# define INIT_CAM 1

/* ________________________________ FUNCTION ________________________________ */
/* parser */
t_element	ft_parse_rt(int fd);
/* convertor */
t_vec		vec(char *vec);
t_point		point(char *pos);
t_color		color(char *rgb);
int			arg_len(char **vals);
/* constructor.c */
t_object	*create_cylinder(char **vals);
t_object	*create_plane(char **vals);
t_object	*create_sphere(char **vals);
t_object	*create_cone(char **vals);
void		create_light(t_light **head, char **vals);
/* constructor2.c */
t_ambient	create_ambient(char **vals);
t_camera	create_camera(char **vals);

t_element	ft_parse_rt(int fd);
char		**rt_split(char *str);
void		*ft_split_error(char **str, int size);

/* validate.c */
int			validate_nvec(char **val);
int			validate_color(char **val);
int			validate_ratio(char *val);

/* parse_utils.c */
void		add_light_to_list(t_light **head, t_light *new);
void		ft_clear_char(char **str);
int			atod(char *str, double *result);

#endif
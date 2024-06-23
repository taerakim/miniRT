/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/23 16:37:47 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "rt_struct.h"
# include "libft.h"

/* parser */
t_element	ft_parse_rt(int fd);
/* convertor */
t_vec		vec(char *vec);
t_point		point(char *pos);
t_color		color(char *rgb);
t_ambient	create_ambient(char **vals);
t_camera	create_camera(char **vals);
t_light		create_light(char **vals);
t_object	*create_cylinder(char **vals);
t_object	*create_plane(char **vals);
t_object	*create_sphere(char **vals);

t_element	ft_parse_rt(int fd);
char		**rt_split(char *str);
void		*ft_split_error(char **str, int size);

/* test atod*/
int			atod(char *str, double *result);
void		print_element(t_element *elem);
int			arg_len(char **vals);

#endif
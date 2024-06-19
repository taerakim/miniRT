/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 15:36:16 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/19 16:26:20 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include "rt_struct.h"
# include "libft.h"

/* convertor */
t_vec		convert_vec(char *vec);
t_point		convert_point(char *pos);
t_color		convert_color(char *rgb);
t_ambient	create_ambient(char **vals);
t_camera	create_camera(char **vals);
t_light		create_light(char **vals);
t_object	*create_cylinder(char **vals);
t_object	*create_plane(char **vals);
t_object	*create_sphere(char **vals);
/* parser */

#endif
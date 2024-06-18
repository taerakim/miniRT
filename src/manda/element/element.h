/*   Created: 2024/06/16 04:53:06 by taerakim          #+#    #+#             */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "vector.h"

typedef struct s_ambient_light
{
	double	ratio;
	double	r;
	double	g;
	double	b;
}	t_ambient_light;

typedef struct s_camera
{
	t_vec	view_point;
	double	y;
	double	z;
}	t_camera;
//ㅎㅡㅁ ㅇㅣ거ㄹ 다 짜놔야하는 걸까?

#endif
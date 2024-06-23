/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 18:35:21 by taerakim          #+#    #+#             */
/*   Updated: 2024/06/21 19:46:20 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//void	render_process(t_element *element, t_mlx *env, t_vec ray)
//{
//	//1. 1개의 ray를 구하고 or 가진채로
//	//2. 모든 object를 돌며 hit판정
//		//3. hit된 것을 빛에 도달하는지 다른오브젝트의 부딪히는 지 등 또 hit검사
//	//4. 최종으로 조명 정도와 그런 것들을 계산 후 put_pixel()
//}

void	render(t_element *element, t_mlx *env)
{
	int		i;
	int		k;
	t_vec	ray;

	k = 0;
	while (k < WINDOW_H)
	{
		i = 0;
		while (i < WINDOW_W)
		{
			ray = get_ray(&element->camera, i, k);
			if (hit_object(&element->camera, element->objs, ray) == true)
				put_pixel(&env->img, i, k, 0X00559966);
			if (hit_object(&element->camera, element->objs->next, ray) == true)
				put_pixel(&env->img, i, k, 0X0000FF99);
			i++;
		}
		k++;
	}
}

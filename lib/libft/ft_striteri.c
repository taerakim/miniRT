/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:06:22 by taerakim          #+#    #+#             */
/*   Updated: 2024/01/11 16:13:59 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		f(idx, &s[idx]);
		idx++;
	}
}

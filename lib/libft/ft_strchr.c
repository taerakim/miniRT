/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 16:34:30 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:18 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	size_t			idx;

	idx = 0;
	while (idx <= len)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)s + idx);
		idx++;
	}
	return ((void *)0);
}

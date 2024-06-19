/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:17:13 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:51 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const size_t	len = ft_strlen(s);
	size_t			idx;

	idx = len;
	while (idx >= 0)
	{
		if (s[idx] == (unsigned char)c)
			return ((char *)(s + idx));
		idx--;
	}
	return (0);
}

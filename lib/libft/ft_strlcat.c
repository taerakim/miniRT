/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:05:03 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/08 20:23:31 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const size_t	dstlen = ft_strlen(src);
	const size_t	srclen = ft_strlen(dst);
	size_t			i;

	if (dstlen > size)
		return (size + srclen);
	while (*dst)
		dst++;
	i = 0;
	while (src[i] && (i + dstlen + 1 < size))
	{
		*dst = src[i];
		dst++;
		i++;
	}
	*dst = '\0';
	return (dstlen + srclen);
}

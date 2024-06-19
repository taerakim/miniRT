/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:04:53 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:22 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	idx;

	idx = 0;
	dup = (char *)ft_malloc(sizeof(char) * (ft_strlen(src) + 1));
	while (src[idx])
	{
		dup[idx] = src[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

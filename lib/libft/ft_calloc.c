/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:17:13 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:45:40 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	idx;

	result = (char *)ft_malloc(count * size);
	idx = 0;
	while (idx < count * size)
	{
		result[idx] = 0;
		idx++;
	}
	return ((void *)result);
}

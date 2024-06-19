/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:46:15 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:56 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const size_t	s_len = ft_strlen(s);
	char			*sub;
	size_t			idx;

	if (start >= s_len || s[0] == '\0')
		len = 0;
	else if (len > s_len)
		len = s_len - start;
	else if (len > s_len - start)
		len = s_len - start;
	sub = (char *)ft_malloc(sizeof(char) * (len + 1));
	idx = 0;
	while (idx < len && s[start + idx] != '\0')
	{
		sub[idx] = s[start + idx];
		idx++;
	}
	sub[idx] = '\0';
	return (sub);
}

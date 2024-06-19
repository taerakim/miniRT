/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:58:02 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:27 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const size_t	s1_len = ft_strlen(s1);
	const size_t	s2_len = ft_strlen(s2);
	char			*res;
	size_t			idx;

	res = (char *)ft_malloc(sizeof(char) * (s1_len + s2_len + 1));
	idx = 0;
	while (idx < s1_len)
	{
		res[idx] = s1[idx];
		idx++;
	}
	idx = 0;
	while (idx < s2_len)
	{
		res[s1_len + idx] = s2[idx];
		idx++;
	}
	res[s1_len + s2_len] = '\0';
	return (res);
}

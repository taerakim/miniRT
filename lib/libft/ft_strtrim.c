/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:25:12 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/18 10:54:57 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char const s, char const *set)
{
	int	idx;

	idx = 0;
	while (set[idx])
	{
		if (set[idx] == s)
			return (1);
		idx++;
	}
	return (0);
}

static char	*_strndup(const char *src, size_t n)
{
	char	*dup;
	size_t	idx;

	dup = (char *)ft_malloc(sizeof(char) * (n + 1));
	idx = 0;
	while (idx < n)
	{
		dup[idx] = src[idx];
		idx++;
	}
	dup[idx] = '\0';
	return (dup);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const size_t	len = ft_strlen(s1);
	char			*res;
	size_t			front_idx;
	size_t			back_idx;

	front_idx = 0;
	back_idx = len;
	if (isset(s1[front_idx], set))
		while (isset(s1[front_idx], set) && front_idx < len)
			front_idx++;
	if (front_idx != len)
	{
		if (isset(s1[back_idx - 1], set))
			while (isset(s1[back_idx - 1], set))
				back_idx--;
	}
	res = _strndup(&s1[front_idx], back_idx - front_idx);
	return (res);
}

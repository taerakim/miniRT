/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:05:31 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 14:08:36 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_contain(const char set[7], char c);
static char	*ft_cutword(const char *s, const char set[7], int *search_idx);
static char	*ft_allocword(const char *s, int size);
static int	ft_countwords(const char *s, const char set[7]);

static int	is_contain(const char set[7], char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_cutword(const char *s, const char set[7], int *search_idx)
{
	char	*word;
	int		wordlen;

	wordlen = 0;
	while (s[wordlen + *search_idx] \
	&& !is_contain(set, s[wordlen + *search_idx]))
		wordlen++;
	word = ft_allocword(&s[*search_idx], wordlen);
	if (word == NULL)
		return (NULL);
	while (s[wordlen + *search_idx] \
	&& is_contain(set, s[wordlen + *search_idx]))
		(*search_idx)++;
	*search_idx += wordlen;
	return (word);
}

static char	*ft_allocword(const char *s, int size)
{
	char	*word;
	int		i;

	word = (char *)ft_calloc(1, size + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		word[i] = s[i];
		i++;
	}
	return (word);
}

static int	ft_countwords(const char *s, const char set[7])
{
	int	isword;
	int	count;

	isword = 0;
	count = 0;
	while (*s)
	{
		if (!isword && !is_contain(set, *s))
		{
			isword = 1;
			count++;
		}
		if (isword && is_contain(set, *s))
			isword = 0;
		s++;
	}
	return (count);
}

char	**rt_split(char *str)
{
	const char	set[7] = {'\t', '\n', '\v', '\f', '\r', ' ', 0};
	char		**res;
	int			search_idx;
	int			size;
	int			i;

	search_idx = 0;
	size = ft_countwords(str, set);
	if (size < 1)
		return (NULL);
	res = (char **)ft_calloc(8, size + 1);
	while (str[search_idx] && is_contain(set, str[search_idx]))
		search_idx++;
	i = -1;
	while (++i < size)
	{
		res[i] = ft_cutword(str, set, &search_idx);
		if (res[i] == NULL)
			return (ft_split_error(res, i));
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 16:48:00 by taerakim          #+#    #+#             */
/*   Updated: 2024/02/08 19:47:12 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	wordcnt;
	size_t	idx;

	if (s[0] == '\0')
		return (0);
	wordcnt = 0;
	if (s[0] != c)
		wordcnt = 1;
	idx = 1;
	while (s[idx])
	{
		if (s[idx - 1] == c && s[idx] != c)
			wordcnt++;
		idx++;
	}
	return (wordcnt);
}

static char	*word_dup(char const *s, char c)
{
	char	*word;
	size_t	len;
	size_t	idx;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	word = (char *)ft_malloc(sizeof(char) * (len + 1));
	idx = 0;
	while (idx < len)
	{
		word[idx] = s[idx];
		idx++;
	}
	word[idx] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	const size_t	wordcnt = count_word(s, c);
	char			**result;
	size_t			cnt;
	size_t			idx;

	if (wordcnt == 0)
		return (NULL);
	result = (char **)ft_calloc(wordcnt + 1, sizeof(char *));
	cnt = 0;
	if (s[0] != c)
	{
		result[cnt] = word_dup(s, c);
		cnt += 1;
	}
	idx = 1;
	while (cnt < wordcnt)
	{
		if (s[idx - 1] == c && s[idx] != c)
		{
			result[cnt] = word_dup(&s[idx], c);
			cnt++;
		}
		idx++;
	}
	return (result);
}

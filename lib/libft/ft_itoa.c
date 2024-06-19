/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:49:20 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/18 10:55:21 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_digit_count(long long n, int base_len)
{
	int	cnt;

	if (n == 0)
		return (1);
	cnt = 0;
	if (n < 0)
		cnt = 1;
	while (n != 0)
	{
		n = n / base_len;
		cnt++;
	}
	return (cnt);
}

char	*ft_itoa(int num)
{
	char		*res;
	const int	cnt_digit = _digit_count(num, 10);
	int			idx;

	if (num == -2147483648)
		return (ft_strdup("-2147483648"));
	res = (char *)ft_malloc(sizeof(char) * (cnt_digit + 1));
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
	}
	idx = 1;
	while (num > 9)
	{
		res[cnt_digit - idx] = num % 10 + '0';
		num = num / 10;
		idx++;
	}
	res[cnt_digit - idx] = num % 10 + '0';
	res[cnt_digit] = '\0';
	return (res);
}

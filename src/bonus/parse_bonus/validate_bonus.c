/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:32:42 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 14:59:35 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse_bonus.h"
#include "ft_error_bonus.h"
#include "vector_bonus.h"

int	validate_nvec(char **val)
{
	double	n;
	int		i;

	i = 0;
	while (val && val[i])
	{
		atod(val[i], &n);
		if (-1 > n || 1 < n)
			return (0);
		i++;
	}
	return (1);
}

int	validate_color(char **val)
{
	double	n;
	int		i;

	i = 0;
	while (val && val[i])
	{
		atod(val[i], &n);
		if (0 > n || 255 < n)
			return (0);
		i++;
	}
	return (1);
}

int	validate_ratio(char *val)
{
	double	n;

	atod(val, &n);
	if (0 > n || 1 < n)
		return (0);
	return (1);
}

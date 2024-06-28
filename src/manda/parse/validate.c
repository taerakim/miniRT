/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 13:32:42 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:37:55 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "parse.h"
#include "ft_error.h"
#include "vector.h"

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

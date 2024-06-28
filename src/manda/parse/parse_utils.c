/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:45:03 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 13:30:23 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "parse.h"
#include "ft_error.h"

static int	_handle_prev(char *str, double *result, int *sign)
{
	int	idx;

	*result = 0.0;
	*sign = 1;
	idx = 0;
	while ((9 <= str[idx] && str[idx] <= 13) || str[idx] == 32)
		idx++;
	if (str[idx] == '-')
		*sign = -1;
	if (str[idx] == '-' || str[idx] == '+')
		idx++;
	return (idx);
}

int	atod(char *str, double *result)
{
	double	fraction;
	int		sign;
	int		idx;

	if (str == NULL)
		return (0);
	idx = _handle_prev(str, result, &sign);
	fraction = 0.1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		*result = *result * 10.0 + (str[idx] - '0');
		idx++;
	}
	if (str[idx] == '.')
		idx += 1;
	while ('0' <= str[idx] && str[idx] <= '9')
	{
		*result += (str[idx] - '0') * fraction;
		fraction *= 0.1;
		idx++;
	}
	*result *= sign;
	if (str[idx] != '\0')
		ft_error(error_init);
	return (1);
}

void	add_light_to_list(t_light **head, t_light *new)
{
	t_light	*ptr;

	ptr = *head;
	if (ptr == NULL)
	{
		*head = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_clear_char(char **str)
{
	int	i;

	i = 0;
	while (str && str[i])
		free(str[i++]);
	free(str);
}

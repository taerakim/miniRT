/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeondcho <yeondcho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:14:56 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/22 16:24:56 by yeondcho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_split_error(char **str, int size)
{
	while (size-- > 0)
		free(str[size]);
	free(str);
	return (NULL);
}

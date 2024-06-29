/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:14:56 by yeondcho          #+#    #+#             */
/*   Updated: 2024/06/28 14:57:33 by taerakim         ###   ########.fr       */
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

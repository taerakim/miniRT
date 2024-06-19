/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 15:00:54 by taerakim          #+#    #+#             */
/*   Updated: 2024/03/08 20:26:59 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	*ft_malloc(size_t size)
{
	void	*res;

	res = malloc(size);
	if (res == NULL)
	{
		perror("error");
		exit(EXIT_FAILURE);
	}
	return (res);
}

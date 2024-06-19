/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taerakim <taerakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 12:00:51 by taerakim          #+#    #+#             */
/*   Updated: 2024/01/01 15:22:29 by taerakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	write_n(int num, int fd)
{
	char	n;

	if (num < 0)
		n = '0' + num % 10 * (-1);
	else
		n = '0' + num % 10;
	if (num / 10 != 0)
	{
		write_n(num / 10, fd);
	}
	write(fd, &n, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n < 0)
	{
		write(fd, "-", 1);
		write_n(n, fd);
	}
	else
		write_n(n, fd);
}

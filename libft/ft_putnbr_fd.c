/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:44:26 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 13:53:13 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit[12];
	int		is_minus;
	int		index;

	is_minus = 1;
	index = 0;
	if (n == 0)
		write(fd, "0", 1);
	else
	{
		if (n < 0)
			is_minus = -1;
		while (n != 0)
		{
			digit[index] = (char)(((n % 10) * is_minus) + '0');
			n = n / 10;
			index++;
		}
		if (is_minus < 0)
			write(fd, "-", 1);
		while (--index)
			write(fd, &digit[index], 1);
		write(fd, &digit[index], 1);
	}
}

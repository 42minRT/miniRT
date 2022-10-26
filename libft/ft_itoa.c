/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 20:03:45 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 13:50:32 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_size_of_int(int n)
{
	int	size;

	if (n == 0)
		return (1);
	size = 0;
	if (n < 0)
		size++;
	while (n)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		is_minus;
	int		size;

	size = ft_size_of_int(n);
	ret = (char *)malloc(sizeof(char) * (size + 1));
	if (!ret)
		return (0);
	ret[size] = 0;
	is_minus = 1;
	if (n < 0)
		is_minus = -1;
	while (--size)
	{
		ret[size] = (char)((n % 10) * is_minus + '0');
		n = n / 10;
	}
	ret[size] = (char)(n * is_minus + '0');
	if (is_minus < 0)
		ret[0] = '-';
	return (ret);
}

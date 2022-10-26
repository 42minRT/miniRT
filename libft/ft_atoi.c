/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:51:12 by jimin             #+#    #+#             */
/*   Updated: 2021/12/09 17:19:43 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v' \
			|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	char	is_minus;

	result = 0;
	is_minus = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
		is_minus = *(str++);
	while (ft_isdigit(*str))
	{
		result = (result * 10) + *str - '0';
		str++;
	}
	if (is_minus == '-')
		result = -result;
	return (result);
}

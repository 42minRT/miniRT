/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:00:01 by jimin             #+#    #+#             */
/*   Updated: 2021/12/06 14:07:05 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	input;

	input = (char) c;
	while (*s)
	{
		if (*s == input)
			return ((char *) s);
		s++;
	}
	if (c == '\0')
		return ((char *) s);
	return (0);
}

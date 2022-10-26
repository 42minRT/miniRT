/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:29:27 by jimin             #+#    #+#             */
/*   Updated: 2021/12/06 16:19:19 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*us1;
	unsigned char	*us2;
	size_t			index;

	us1 = (unsigned char *) s1;
	us2 = (unsigned char *) s2;
	index = 1;
	if (n)
	{
		while (*us1 && *us1 == *us2 && index < n)
		{
			us1++;
			us2++;
			index++;
		}
		return (*us1 - *us2);
	}
	return (0);
}

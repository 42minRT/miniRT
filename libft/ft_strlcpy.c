/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 12:02:31 by jimin             #+#    #+#             */
/*   Updated: 2021/12/06 14:07:56 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	src_size;

	index = 0;
	src_size = ft_strlen(src);
	while (index + 1 < dstsize && src[index])
	{
		dst[index] = src[index];
		index++;
	}
	if (dstsize)
		dst[index] = '\0';
	return (src_size);
}

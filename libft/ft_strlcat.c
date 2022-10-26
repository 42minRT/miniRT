/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 20:57:08 by jimin             #+#    #+#             */
/*   Updated: 2021/12/16 18:35:58 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize && dstlen + 1 <= dstsize)
	{
		while (index + dstlen + 1 < dstsize && *(src + index))
		{
			*((dstlen + dst) + index) = *(src + index);
			index++;
		}
		*((dst + dstlen) + index) = '\0';
		return (dstlen + srclen);
	}
	return (srclen + dstsize);
}

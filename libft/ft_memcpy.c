/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 18:32:13 by jimin             #+#    #+#             */
/*   Updated: 2021/12/09 17:01:00 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			index;	
	unsigned char	*src_uc;
	unsigned char	*dst_uc;

	if (!src && !dst)
		return (dst);
	index = 0;
	src_uc = (unsigned char *)src;
	dst_uc = (unsigned char *)dst;
	while (index < n)
	{
		*(dst_uc) = *(src_uc);
		dst_uc++;
		src_uc++;
		index++;
	}
	return (dst);
}

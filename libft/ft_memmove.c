/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 21:21:06 by jimin             #+#    #+#             */
/*   Updated: 2022/04/15 15:05:56 by jhmin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	unsigned char	*src_uc;
	unsigned char	*dst_uc;

	if (dst < src)
		ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		if (!src && !dst)
			return (dst);
		src_uc = (unsigned char *)(src + len - 1);
		dst_uc = (unsigned char *)(dst + len - 1);
		while (len--)
			*(dst_uc--) = *(src_uc--);
	}
	return (dst);
}

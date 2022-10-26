/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 13:47:25 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 12:42:12 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	haylen;
	size_t	need_len;
	size_t	s_index;
	size_t	index;

	haylen = ft_strlen(haystack);
	need_len = ft_strlen(needle);
	s_index = 0;
	while (s_index + need_len <= haylen && s_index + need_len <= len)
	{
		index = 0;
		while (index < need_len && haystack[index] == needle[index])
			index++;
		if (index == need_len)
			return ((char *)haystack);
		haystack++;
		s_index++;
	}
	return (0);
}

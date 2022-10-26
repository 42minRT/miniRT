/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:19:24 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 14:51:24 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	s_len;
	size_t	alloc_len;

	s_len = ft_strlen(s);
	ret = NULL;
	if (start < s_len)
	{
		alloc_len = s_len - start + 1;
		if (alloc_len > len)
			alloc_len = len + 1;
		ret = (char *) malloc(sizeof(char) * (alloc_len));
		if (!ret)
			return (0);
		ft_strlcpy(ret, s + start, len + 1);
	}
	else
		ret = ft_strdup("");
	return (ret);
}

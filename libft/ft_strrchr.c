/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 17:12:55 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 12:35:12 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	char	*str;

	str = (char *) s;
	s_len = ft_strlen(s) + 1;
	while (s_len--)
	{
		if (*(str + s_len) == (char)c)
			return (str + s_len);
	}
	return (0);
}

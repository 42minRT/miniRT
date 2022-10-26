/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 21:15:28 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 13:50:54 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	unsigned int	size;
	char			*ret;

	index = 0;
	size = ft_strlen(s);
	ret = (char *) ft_calloc(sizeof(char), size + 1);
	if (!ret)
		return (0);
	while (index < size)
	{
		ret[index] = f(index, s[index]);
		index++;
	}
	return (ret);
}

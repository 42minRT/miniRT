/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:01:35 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 13:46:52 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_trim_start(char const *s, char const *set, size_t s_len)
{
	while (ft_strchr(set, *s) && s_len--)
		s++;
	return ((char *) s);
}

static char	*ft_trim_end(char *start, char *end, char const *set)
{
	while (ft_strchr(set, *end) && start <= end)
		end--;
	return (end);
}

static int	ft_trim_size(char *start, char *end)
{
	int	ret;

	ret = (int)(end - start + 1);
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start;
	char	*end;
	char	*str;
	int		len;
	int		str_len;

	len = ft_strlen(s1);
	start = ft_trim_start(s1, set, len);
	end = (char *)(s1 + len - 1);
	end = ft_trim_end(start, end, set);
	str_len = ft_trim_size(start, end);
	str = (char *) malloc(sizeof(char) * (str_len + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, start, str_len + 1);
	return (str);
}

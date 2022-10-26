/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:46:50 by jimin             #+#    #+#             */
/*   Updated: 2021/12/08 14:41:26 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_next_token(const char *s, int c)
{
	while (*s && *s != c)
		s++;
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static unsigned int	ft_token_count(const char *s, char c)
{
	unsigned int	count;

	count = 0;
	while (*s)
	{
		s = ft_next_token(s, c);
		count++;
	}
	return (count);
}

static char	*ft_get_token(const char *s, char c)
{
	char			*ret;
	unsigned int	len;

	len = 0;
	while (s[len] != c && s[len] != '\0')
		len++;
	ret = (char *) malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	ft_strlcpy(ret, (char *)s, len + 1);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	unsigned int	count;
	unsigned int	index;
	char			**ret;

	while (*s && *s == c)
		s++;
	count = ft_token_count(s, c);
	ret = (char **) malloc(sizeof(char *) * (count + 1));
	if (!ret)
		return (0);
	index = 0;
	while (index < count)
	{
		ret[index] = ft_get_token(s, c);
		if (ret[index++] == NULL)
		{
			while (count--)
				free(ret[count]);
			free(ret);
			return (0);
		}
		s = ft_next_token(s, c);
	}
	ret[index] = 0;
	return (ret);
}

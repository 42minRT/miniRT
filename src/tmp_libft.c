#include "../include/parse.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = s;
	while (n > 0)
	{
		*ptr++ = 0;
		--n;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ary;

	ary = malloc(count * size);
	if (ary == 0)
		return (0);
	ft_bzero(ary, count * size);
	return (ary);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s && s[len])
		++len;
	return (len);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*dest;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == 0)
		return (0);
	while (i < len)
	{
		dest[i] = s1[i];
		++i;
	}
	dest[i] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (start + len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	substr = (char *)malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		++i;
	}
	substr[i] = '\0';
	return (substr);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	i = 0;
	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	while (i < n)
	{
		if (!ss1[i] && !ss2[i])
			return (0);
		else if (ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i] && dstsize > i + 1)
	{
		dst[i] = src[i];
		++i;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

static int	ft_word_count(char const *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
		{
			++cnt;
			while (*str != c && *str)
				++str;
		}
		while (*str == c && *str)
			++str;
	}
	return (cnt);
}

static char	**ft_free_array(char **array, int end)
{
	int	i;

	i = 0;
	while (i < end)
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	return (NULL);
}

static char	**ft_put_array(char **array, char const *str, char c)
{
	char	*wd_start;
	int		word_len;
	int		i;

	word_len = 0;
	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			wd_start = &(*(char *)str);
			while (*str && *str != c && ++word_len)
				++str;
			array[i] = (char *)malloc(sizeof(char) * (word_len + 1));
			if (array[i] == NULL)
				return (ft_free_array(array, i));
			ft_strlcpy(array[i], wd_start, word_len + 1);
			++i;
			word_len = 0;
		}
		else if (*str == c)
			++str;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		word_cnt;

	if (s == NULL)
		return (NULL);
	word_cnt = ft_word_count(s, c);
	array = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (array == NULL)
		return (NULL);
	array[word_cnt] = 0;
	array = ft_put_array(array, s, c);
	return (array);
}

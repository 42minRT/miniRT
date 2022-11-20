/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seongyle <seongyle@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:52:25 by seongyle          #+#    #+#             */
/*   Updated: 2022/11/20 16:52:26 by seongyle         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

int	init_string(t_string *t_str)
{
	size_t	index;

	t_str->line = (char *)malloc(sizeof(char) * (BUFFER_SIZE));
	if (!t_str->line)
		return (0);
	index = 0;
	while (index < BUFFER_SIZE)
		t_str->line[index++] = 0;
	t_str->size = BUFFER_SIZE;
	t_str->len = 0;
	return (1);
}

t_buffer	*init_buffer(int fd)
{
	size_t		index;
	t_buffer	*t_buf;

	t_buf = (t_buffer *)malloc(sizeof(t_buffer));
	t_buf->fd = fd;
	t_buf->buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!t_buf->buf)
		return (0);
	index = 0;
	while (index < BUFFER_SIZE)
		t_buf->buf[index++] = 0;
	t_buf->cur = t_buf->buf;
	t_buf->end = t_buf->buf;
	t_buf->next = NULL;
	return (t_buf);
}

void	ft_free_buf(t_buffer *head, int fd)
{
	t_buffer	*cur;
	t_buffer	*cur_next;

	cur = head;
	while (cur->next)
	{
		cur_next = cur->next;
		if (cur_next->fd == fd)
		{
			cur->next = cur_next->next;
			free(cur_next->buf);
			cur_next->buf = 0;
			free(cur_next);
			cur_next = 0;
			break ;
		}
		cur = cur->next;
	}
}

char	*ft_copy_string(char *dst, t_string *t_str)
{
	size_t	index;

	if (t_str->len == 0)
		return (0);
	index = 0;
	dst = (char *)malloc(sizeof(char) * (t_str->len + 1));
	if (!dst)
		return (0);
	while (index < t_str->len)
	{
		dst[index] = t_str->line[index];
		index++;
	}
	dst[index] = 0;
	return (dst);
}

int	ft_str_append(t_string *t_str, char c)
{
	char	*temp;
	size_t	index;

	if (t_str->size <= t_str->len)
	{
		t_str->size = t_str->size + BUFFER_SIZE;
		temp = (char *)malloc(sizeof(char) * (t_str->size));
		if (!temp)
			return (0);
		index = 0;
		while (index < t_str->len)
		{
			temp[index] = t_str->line[index];
			index++;
		}
		free(t_str->line);
		t_str->line = temp;
	}
	t_str->line[t_str->len] = c;
	(t_str->len)++;
	return (1);
}

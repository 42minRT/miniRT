/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekim <jaekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:27:54 by jaekim            #+#    #+#             */
/*   Updated: 2022/11/10 19:27:55 by jaekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parse.h"

t_buffer	*ft_bring_buffer(t_buffer *head, int fd)
{
	t_buffer	*cur;

	if (!head->next)
	{
		head->next = init_buffer(fd);
		if (!head->next)
			return (0);
		return (head->next);
	}
	cur = head;
	while (cur->next)
	{
		cur = cur->next;
		if (cur->fd == fd)
			return (cur);
	}
	cur = init_buffer(fd);
	cur->next = head->next;
	head->next = cur;
	if (!cur)
		return (0);
	return (cur);
}

char	ft_get_char(int fd, t_buffer *t_buf, int *eof)
{
	int	readout;

	if (t_buf->cur == t_buf->end)
	{
		if (t_buf->end < t_buf->buf + BUFFER_SIZE && t_buf->end > t_buf->buf)
		{
			*eof = 1;
			return (0);
		}
		readout = read(fd, t_buf->buf, BUFFER_SIZE);
		t_buf->end = t_buf->buf + readout;
		t_buf->cur = t_buf->buf;
	}
	if (t_buf->cur > t_buf->end)
		*eof = -1;
	else if (t_buf->cur == t_buf->end)
		*eof = 1;
	else
	{
		*eof = 0;
		return (*((t_buf->cur)++));
	}
	return (0);
}

int	ft_get_line(int fd, t_string *t_str, t_buffer *head)
{
	char		c;
	int			eof;

	while (1)
	{
		c = ft_get_char(fd, ft_bring_buffer(head, fd), &eof);
		if (eof == -1)
		{
			ft_free_buf(head, fd);
			return (0);
		}
		else if (eof == 1)
		{
			ft_free_buf(head, fd);
			break ;
		}
		if (!ft_str_append(t_str, c))
			return (0);
		if (c == '\n')
			break ;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static t_buffer	head;
	t_string		t_str;
	char			*ret;

	ret = 0;
	t_str.line = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!init_string(&t_str))
		return (NULL);
	if (!ft_get_line(fd, &t_str, &head))
	{
		free(t_str.line);
		return (NULL);
	}
	ret = ft_copy_string(ret, &t_str);
	if (!ret)
	{
		free(t_str.line);
		return (NULL);
	}
	free(t_str.line);
	return (ret);
}

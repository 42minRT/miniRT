/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 10:04:12 by jimin             #+#    #+#             */
/*   Updated: 2022/06/10 21:04:32 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define BUFFER_SIZE 42

typedef struct s_string
{
	char	*line;
	size_t	len;
	size_t	size;
}	t_string;

typedef struct s_buffer
{
	int				fd;
	char			*buf;
	char			*cur;
	char			*end;
	struct s_buffer	*next;
}	t_buffer;

char		*get_next_line(int fd);
int			ft_get_line(int fd, t_string *t_str, t_buffer *head);
char		ft_get_char(int fd, t_buffer *t_buf, int *eof);
t_buffer	*ft_bring_buffer(t_buffer *buf_head, int fd);
int			init_string(t_string *t_str);
t_buffer	*init_buffer(int fd);
void		ft_free_buf(t_buffer *buf, int fd);
char		*ft_copy_string(char *dst, t_string *t_str);
int			ft_str_append(t_string *t_str, char c);

#endif

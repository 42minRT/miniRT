/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimin <jimin@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 18:09:26 by jimin             #+#    #+#             */
/*   Updated: 2022/01/31 18:09:33 by jimin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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

#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "structures.h"
# include "libft.h"
# include "utils.h"


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

//gnl 함수
char		*get_next_line(int fd);
int			ft_get_line(int fd, t_string *t_str, t_buffer *head);
char		ft_get_char(int fd, t_buffer *t_buf, int *eof);
t_buffer	*ft_bring_buffer(t_buffer *buf_head, int fd);
int			init_string(t_string *t_str);
t_buffer	*init_buffer(int fd);
void		ft_free_buf(t_buffer *buf, int fd);
char		*ft_copy_string(char *dst, t_string *t_str);
int			ft_str_append(t_string *t_str, char c);

// parse
t_error	validate_file(int argc, char **argv, t_rt_list **file);

// is_valid_elements_utils_base
t_is_return	is_valid_double_format(char *to_double_str);
t_is_return is_between(double conditional_num1, double conditional_num2, double num);
t_is_return is_xyz_element(char *str);
t_is_return	is_rgb_element(char *str);
t_is_return	is_vector_element(char *str);

// is_valid_elements_utils
t_is_return	is_xyz_coordinate(char *str);
t_is_return	is_rgb(char *str);
t_is_return	is_rgb(char *str);
t_is_return	is_3d_norm_orient_vecotor(char *str);

// is_valid_elements
t_is_return	is_valid_a_element(char **elements);
t_is_return	is_valid_c_element(char **elements);
t_is_return	is_valid_l_element(char **elements);
t_is_return	is_valid_sp_element(char **elements);
t_is_return	is_valid_pl_element(char **elements);
t_is_return is_valid_cy_element(char **elements);


//parse_elements
t_is_return	is_rt_file(char *file);
t_is_return	is_valid_type(char *type);
t_is_return	is_valid_elements(char **elements);
t_is_return	parse_elements(char *line, t_rt_list **file);


// rt list
size_t		ft_arrlen(char **array);
t_rt_list	*new_rt_lst(char **content);
void		rt_lstadd_back(t_rt_list **lst, t_rt_list *new_lst);
// 출력용 임시 함수
void		rt_lstprint(t_rt_list *lst);

#endif

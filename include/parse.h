#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "../get_next_line/get_next_line.h"

typedef int	t_error;
# define NO_ERROR 0
# define ARG_ERROR 100
# define ELEMENTS_ERROR 101
# define SYSTEM_ERROR 102

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

typedef struct s_list	t_list;

struct s_list
{
	char	*type;
	char	**elements;
	t_list	*next;
};

// parse
t_error	validate_file(int argc, char **argv, t_list **file);

// rt list
size_t	ft_arrlen(char **array);
t_list	*rt_lstnew(char **content);
void	rt_lstadd_back(t_list **lst, t_list *new);
// 출력용 임시 함수
void	rt_lstprint(t_list *lst);

// tmp libft
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

#endif
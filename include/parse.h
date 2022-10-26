#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# include "structures.h"


// parse
t_error	validate_file(int argc, char **argv, t_rt_list **file);

// rt list
size_t		ft_arrlen(char **array);
t_rt_list	*rt_lstnew(char **content);
void		rt_lstadd_back(t_rt_list **lst, t_rt_list *new_lst);
// 출력용 임시 함수
void		rt_lstprint(t_rt_list *lst);

// tmp libft
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

#endif

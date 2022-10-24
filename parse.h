#ifndef PARSE_H
# define PARSE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line/get_next_line.h"

typedef int	t_error;
# define NO_ERROR 0
# define ARG_ERROR 100
# define ELEMENTS_ERROR 101
# define SYSTEM_ERROR 102

typedef int	t_bool;
# define FALSE 0
# define TRUE 1

// parse
t_error	validate_file(int argc, char **argv);

// tmp libft
size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);

#endif
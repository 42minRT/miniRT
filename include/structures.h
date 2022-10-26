#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "libft.h"
typedef struct s_rt_list	t_rt_list;

typedef enum e_error
{
	NO_ERROR = 0,
	ARG_ERROR = 100,
	ELEMENTS_ERROR = 101,
	SYSTEM_ERROR = 102
}	t_error;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

struct s_rt_list
{
	char	*type;
	char	**elements;
	t_rt_list	*next;
};

#endif

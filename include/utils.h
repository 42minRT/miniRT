#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

t_is_return	free_return(char **target, t_is_return boolean);
void		free_spited(char **target);
double		ft_atod(char *str);
int			count_elements(char **elements);
char		**get_elements_by_type(t_rt_list *file, char *type);

#endif

#ifndef UTILS_H
# define UTILS_H

# include "structures.h"

t_is_return	free_return(char **target, t_is_return boolean);
void		free_spited(char **target);
double		ft_atod(char *str);
int			count_elements(char **elements);

// parse_element
char		**get_elements_by_type(t_rt_list *file, char *type);
t_point3	parse_xyz_coordination(char *xyz_str);
t_color3	parse_rgb(char *rgb);
t_vec3		parse_vec3(char *vector);

#endif

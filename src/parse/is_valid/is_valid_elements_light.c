#include "../../../include/parse.h"

t_is_return	is_valid_a_element(char **elements)
{
	if (count_elements(elements) != 3)
		return (NO);
	if (is_valid_double_format(elements[1]) == NO)
		return (NO);
	if (is_between(0.0, 1.0, ft_atod(elements[1])) == NO)
		return (NO);
	if (is_rgb(elements[2]) == NO)
		return (NO);
	return (YES);
}

t_is_return	is_valid_l_element(char **elements)
{
	if (count_elements(elements) != 4)
		return (NO);
	if (is_xyz_coordinate(elements[1]) == NO)
		return (NO);
	if (is_valid_double_format(elements[2]) == NO)
		return (NO);
	if (is_between(0.0, 1.0, ft_atod(elements[2])) == NO)
		return (NO);
	if (is_rgb(elements[3]) == NO)
		return (NO);
	return (YES);
}

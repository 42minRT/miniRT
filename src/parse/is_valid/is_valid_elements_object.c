#include "../../../include/parse.h"

t_is_return	is_valid_c_element(char **elements)
{
	char	*last_element;

	last_element = elements[count_elements(elements) - 1];
	last_element[ft_strlen(last_element) - 1] = '\0';
	if (count_elements(elements) != 4)
		return (NO);
	if (is_xyz_coordinate(elements[1]) == NO)
		return (NO);
	if (is_3d_norm_orient_vecotor(elements[2]) == NO)
		return (NO);
	if (is_valid_double_format(last_element) == NO)
		return (NO);
	if (is_between(0.0, 180.0, ft_atod(last_element)) == NO)
		return (NO);
	return (YES);
}

t_is_return	is_valid_sp_element(char **elements)
{
	char	*last_element;

	last_element = elements[count_elements(elements) - 1];
	last_element[ft_strlen(last_element) - 1] = '\0';

	if (count_elements(elements) != 4)
		return (NO);
	if (is_xyz_coordinate(elements[1]) == NO)
		return (NO);
	if (is_valid_double_format(elements[2]) == NO)
		return (NO);
	if (ft_atod(elements[2]) < 0.0)
		return (NO);
	if (is_rgb(elements[3]) == NO)
		return (NO);
	return (YES);
}

t_is_return	is_valid_pl_element(char **elements)
{
	char	*last_element;

	last_element = elements[count_elements(elements) - 1];
	last_element[ft_strlen(last_element) - 1] = '\0';
	if (count_elements(elements) != 4)
		return (NO);
	if (is_xyz_coordinate(elements[1]) == NO)
		return (NO);
	if (is_3d_norm_orient_vecotor(elements[2]) == NO)
		return (NO);
	if (is_rgb(elements[3]) == NO)
		return (NO);
	return (YES);
}

t_is_return is_valid_cy_element(char **elements)
{
	char	*last_element;

	last_element = elements[count_elements(elements) - 1];
	last_element[ft_strlen(last_element) - 1] = '\0';
	if (is_xyz_coordinate(elements[1]) == NO)
		return (NO);
	if (is_3d_norm_orient_vecotor(elements[2]) == NO)
		return (NO);
	if (is_valid_double_format(elements[3]) == NO)
		return (NO);
	if (ft_atod(elements[3]) < 0)
		return (NO);
	if (is_valid_double_format(elements[4]) == NO)
		return (NO);
	if (ft_atod(elements[4]) < 0)
		return (NO);
	if (is_rgb(elements[5]) == NO)
		return (NO);
	return (YES);
}
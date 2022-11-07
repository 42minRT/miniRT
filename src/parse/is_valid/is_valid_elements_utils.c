#include "../../../include/parse.h"

t_is_return	is_xyz_coordinate(char *str)
{
	int		i;
	int		xyz_elements_len;
	char	**xyz_elements;

	i = 0;
	xyz_elements = ft_split(str, ',');
	xyz_elements_len = count_elements(xyz_elements);
	if (xyz_elements_len != 3)
		return (free_return(xyz_elements, NO));
	while (i < xyz_elements_len)
	{
		if (is_xyz_element(xyz_elements[i]) == NO)
			return (free_return(xyz_elements, NO));
		++i;
	}
	return (free_return(xyz_elements, YES));
}

t_is_return	is_rgb(char *str)
{
	int		i;
	int		rgb_elements_len;
	char	**rgb_elements;

	i = 0;
	rgb_elements = ft_split(str, ',');
	rgb_elements_len = count_elements(rgb_elements);
	if (rgb_elements_len != 3)
		return (free_return(rgb_elements, NO));
	while (i < rgb_elements_len)
	{
		if (is_rgb_element(rgb_elements[i]) == NO)
			return (free_return(rgb_elements, NO));
		++i;
	}
	return (free_return(rgb_elements, YES));
}

t_is_return	is_3d_norm_orient_vecotor(char *str)
{
	int		i;
	int		vector_elements_len;
	char	**vector_elements;
	double	vector_len_2;

	i = 0;
	vector_elements = ft_split(str, ',');
	vector_elements_len = count_elements(vector_elements);
	vector_len_2 = 0;
	if (vector_elements_len != 3)
		return (free_return(vector_elements, NO));
	while (i < vector_elements_len)
	{
		vector_len_2 += pow(ft_atod(vector_elements[i]), 2.0);
		if (is_vector_element(vector_elements[i]) == NO)
			return (free_return(vector_elements, NO));
		++i;
	}
	if (vector_len_2 < 1 - EPSILON || vector_len_2 > 1 + EPSILON)
		return (free_return(vector_elements, NO));
	return (free_return(vector_elements, YES));
}

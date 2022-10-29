#include "../../../include/parse.h"

t_is_return	is_rt_file(char *file_name)
{
	int		len;
	char	*file_ext;
	t_is_return	match;

	match = NO;
	len = ft_strlen(file_name);
	file_ext = ft_substr(file_name, len - 3, 3);
	if (ft_strncmp(file_ext, ".rt", 3) == 0)
		match = YES;
	free(file_ext);
	return (match);
}

t_is_return	is_valid_type(char *type)
{
	static int	capital_type[3];

	if (ft_strncmp(type, "sp", 3) == 0
		|| ft_strncmp(type, "pl", 3) == 0
		|| ft_strncmp(type, "cy", 3) == 0)
		return (YES);
	if (ft_strncmp(type, "A", 2) == 0)
		++(capital_type[0]);
	else if (ft_strncmp(type, "C", 2) == 0)
		++(capital_type[1]);
	else if (ft_strncmp(type, "L", 2) == 0)
		++(capital_type[2]);
	else
		return (NO);
	if (capital_type[0] > 1 || capital_type[1] > 1 || capital_type[2] > 1)
		return (NO);
	return (YES);
}


t_is_return	is_valid_elements(char **elements)
{
	char		*type;
	t_is_return	ret;

	type = elements[0];
	ret = YES;
	if (ft_strncmp(type, "A", 2) == 0)
		ret = is_valid_a_element(elements);
	else if (ft_strncmp(type, "C", 2) == 0)
		ret = is_valid_c_element(elements);
	else if (ft_strncmp(type, "L", 2) == 0)
		ret = is_valid_l_element(elements);
	else if (ft_strncmp(type, "sp", 3) == 0)
		ret = is_valid_sp_element(elements);
	else if (ft_strncmp(type, "pl", 3) == 0)
		ret = is_valid_pl_element(elements);
	else if (ft_strncmp(type, "cy", 3) == 0)
		ret = is_valid_cy_element(elements);
	return (ret);
}

t_is_return	validate_elements(char *line, t_rt_list **file)
{
	char	**elements;
	char	*type;
	int		i;
	t_rt_list *new;

	elements = ft_split(line, ' ');
	if (count_elements(elements) == 1 && ft_strncmp(elements[0], "\n", 1) == 0)
		return (free_return(elements, YES));
	if (count_elements(elements) < 3)
		return (free_return(elements, NO));
	type = elements[0];
	if (is_valid_type(type) == NO)
		return (free_return(elements, NO));
	// TODO: 각 타입에 맞는 값들, 함수 이름 적절하게 정하기 
	if (is_valid_elements(elements) == NO)
		return (free_return(elements, NO));
	new = new_rt_lst(elements);
	rt_lstadd_back(file, new);
	return (free_return(elements, YES));
}
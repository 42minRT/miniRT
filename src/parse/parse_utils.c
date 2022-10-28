#include "../../include/parse.h"

int		count_elements(char **elements)
{
	int	cnt;

	cnt = 0;
	while (elements[cnt])
		++cnt;
	return (cnt);
}

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

t_is_return	is_valid_double_format(char *to_double_str)
{
	int	i;
	int	dot_cnt;

	i = 0;
	dot_cnt = 0;
	while (to_double_str[i] != NULL)
	{
		if (dot_cnt > 1)
			return (NO);
		if (to_double_str[i] == '.')
		{
			++dot_cnt;
			++i;
		}
		if (ft_isdigit(to_double_str[i]) == FALSE || dot_cnt > 1)
			return (NO);
		++i;
	}
	return (YES);
}

t_is_return is_between(double conditional_num1, double conditional_num2, double num)
{
	double	min;
	double	max;

	if (conditional_num1 < conditional_num2)
	{
		min = conditional_num1;
		max = conditional_num2;
	}
	else
	{
		min = conditional_num2;
		max = conditional_num1;
	}
	if (min <= num && max >= num)
		return (YES);
	return (NO);
}

t_is_return	is_rgb_element(char *str)
{
	if (is_valid_double_format(str) == NO)
		return (NO);
	if (is_between(0, 255, ft_atod(str)) == YES)
		return (YES);
	return (NO);
}

t_is_return	is_rgb(char *str)
{
	int		i;
	int		ret;
	char	**rgb_elements;

	i = 0;
	ret = YES;
	rgb_elements = ft_split(str, ',');
	while (i < 3)
	{
		if (is_rgb_element(rgb_elements[i]) == NO)
			ret = NO;
		++i;
	}
	i = 0;
	while (i < 3)
	{
		free(rgb_elements[i]);
		++i;
	}
	free(rgb_elements);
	return (ret);
}

// TODO: 타입 반환하는 함수 필요
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

t_is_return	is_valid_a_element(char **elements)
{
	if (is_valid_double_format(elements[1]) == NO)
		return (NO);
	if (is_between(0.0, 1.0, ft_atod(elements[1])) == NO)
		return (NO);
	if (is_rgb(elements[2]) == NO)
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
	return (YES);
}

t_bool	free_return(char **target, t_bool boolean)
{
	int	i;

	i = 0;
	while (target && target[i])
	{
		free(target[i]);
		++i;
	}
	if (target)
		free(target);
	return (boolean);
}

t_bool	validate_elements(char *line, t_rt_list **file)
{
	char	**elements;
	char	*type;
	int		i;
	t_rt_list *new;

	elements = ft_split(line, ' ');
	if (count_elements(elements) == 1 && ft_strncmp(elements[0], "\n", 1) == 0)
		return (free_return(elements, TRUE));
	if (count_elements(elements) < 3)
		return (free_return(elements, FALSE));
	type = elements[0];
	if (is_valid_type(type) == NO)
		return (free_return(elements, FALSE));
	// TODO: 각 타입에 맞는 값들, 함수 이름 적절하게 정하기 
	if (is_valid_elements(elements) == NO)
		return (free_return(elements, FALSE));
	new = new_rt_lst(elements);
	rt_lstadd_back(file, new);
	return (free_return(elements, TRUE));
}
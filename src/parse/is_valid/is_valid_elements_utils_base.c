#include "../../../include/parse.h"

t_is_return	is_valid_double_format(char *to_double_str)
{
	int	i;
	int	dot_cnt;

	i = 0;
	dot_cnt = 0;
	while (to_double_str[i] != '\0')
	{
		while (to_double_str[i] == '+' || to_double_str[i] == '-')
			++i;
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

t_is_return	is_between(
		double conditional_num1, double conditional_num2, double num)
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

t_is_return	is_xyz_element(char *str)
{
	if (is_valid_double_format(str) == NO)
		return (NO);
	return (YES);
}

t_is_return	is_rgb_element(char *str)
{
	if (is_valid_double_format(str) == NO)
		return (NO);
	if (is_between(0, 255, ft_atod(str)) == YES)
		return (YES);
	return (NO);
}

t_is_return	is_vector_element(char *str)
{
	if (is_valid_double_format(str) == NO)
		return (NO);
	if (is_between(0.0, 1.0, ft_atod(str)) == YES)
		return (YES);
	return (NO);
}

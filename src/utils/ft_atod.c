#include "../../include/libft.h"
#include "../../include/structures.h"

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\n' || str == '\t')
		return (1);
	if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

static void	skip_space_plus_minus(t_atod *data)
{
	char		*str;
	size_t		*i;
	double		*flag;

	str = data->str;
	i = &(data->i);
	flag = &(data->flag);
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*flag *= -1;
		(*i)++;
	}
}

static void	parse_ft_atod(t_atod *data)
{
	char		*str;
	size_t		*i;
	double		*flag;
	int			*point_flag;
	double		*result;

	str = data->str;
	i = &(data->i);
	flag = &(data->flag);
	point_flag = &(data->point_flag);
	result = &(data->result);
	while (str[*i] && (ft_isdigit(str[*i]) || str[*i] == '.'))
	{
		if (*point_flag == 1 && ft_isdigit(str[*i]))
			*flag /= 10.0;
		if (str[*i] == '.')
		{
			*point_flag += 1;
			if (*point_flag > 1)
				return ;
		}
		else
			(*result) = (*result) * 10.0 + (str[*i] - '0');
		(*i)++;
	}
}

double	ft_atod(char *str)
{
	t_atod	data;

	data.i = 0;
	data.result = 0;
	data.flag = 1;
	data.point_flag = 0;
	data.str = str;
	skip_space_plus_minus(&data);
	parse_ft_atod(&data);
	return (data.result * data.flag);
}

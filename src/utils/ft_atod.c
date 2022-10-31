
#include "../../include/libft.h"

static int	ft_isspace(const char str)
{
	if (str == ' ' || str == '\n' || str == '\t')
		return (1);
	if (str == '\v' || str == '\f' || str == '\r')
		return (1);
	return (0);
}

static void	skip_space_plus_minus(char *str, size_t *i, double *flag)
{
	while (ft_isspace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			*flag *= -1;
		(*i)++;
	}
}

static void parse_ft_atod(double *result, char *str, \
					size_t *i, int *point_flag, double *flag)
{
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
	size_t			i;
	double			result;
	double			flag;
	int				point_flag;

	i = 0;
	result = 0;
	flag = 1;
	point_flag = 0;
	skip_space_plus_minus(str, &i, &flag);
	parse_ft_atod(&result, str, &i, &point_flag, &flag);
	return (result * flag);
}

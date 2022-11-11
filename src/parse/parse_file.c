#include "../../include/parse.h"

static t_is_return	is_valid_type_count(t_rt_list **file)
{
	static int		capital_type[3];
	t_rt_list		*cur;
	t_object_type	type;

	cur = *file;
	while (cur)
	{
		type = cur->type;
		if (type == A)
			++(capital_type[0]);
		else if (type == C)
			++(capital_type[1]);
		else if (type == L)
			++(capital_type[2]);
		cur = cur->next;
	}
	if (capital_type[0] > 1 || capital_type[1] > 1 || capital_type[2] > 1)
		return (NO);
	if (capital_type[0] == 0 || capital_type[1] == 0 || capital_type[2] == 0)
		return (NO);
	return (YES);
}

t_error	parse_file(int argc, char **argv, t_rt_list **file)
{
	int		fd;
	char	*buf;

	if (argc != 2 || is_rt_file(argv[1]) == NO)
		return (ARG_ERROR);
	fd = open(argv[1], O_RDONLY);
	if (fd <= 0)
		return (SYSTEM_ERROR);
	*file = NULL;
	while (1)
	{
		buf = get_next_line(fd);
		if (buf == NULL)
			break ;
		write(1, buf, ft_strlen(buf));
		if (parse_elements(buf, file) == FALSE)
			return (ELEMENTS_ERROR);
		free(buf);
	}
	if (is_valid_type_count(file) == NO)
		return (ELEMENTS_ERROR);
	return (NO_ERROR);
}
